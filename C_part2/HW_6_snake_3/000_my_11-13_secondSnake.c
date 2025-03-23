#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>


//#define DEBUG
#ifdef DEBUG
#define Deb if(1)
#else
#define Deb if(0)
#endif


#define MIN_Y  1                                                        //1i достаточео 1й строки
double DELAY = 0.1;
#define PLAYERS  2

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=1, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=20,CONTROLS=2};
//enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=20, MAX_FOOD_SIZE=500, FOOD_EXPIRE_SECONDS=1,SEED_NUMBER=500,CONTROLS=2}; //для отладки функции repairSeed


int badSeedS,badSeedF=0; //считаем плохие зерна на змейке и на еде


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
    {'s', 'w', 'a', 'd'}
};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;
/*
 Еда — это массив точек, состоящий из координат x,y, времени,
 когда данная точка была установлена, и поля, сигнализирующего,
 была ли данная точка съедена.
 */
struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initFood(struct food f[], size_t size)
{
    struct food init = {0,10,0,0,0};                                    //2i 11.03.25 убираем затирание символа U
    for(size_t i=0; i<size; i++)
    {
        f[i] = init;
    }
}
/*
 Обновить/разместить текущее зерно на поле
 */
void putFoodSeed(struct food *fp)
{
    int max_x=0, max_y=0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp->point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}

/*
 Разместить еду на поле
 */
void putFood(struct food f[], size_t number_seeds)
{
    for(size_t i=0; i<number_seeds; i++)
    {
        putFoodSeed(&f[i]);
    }
}

void refreshFood(struct food f[], int nfood)
{
    for(size_t i=0; i<nfood; i++)
    {
        if( f[i].put_time )
        {
            if( !f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS )
            {
                putFoodSeed(&f[i]);
            }
        }
    }
}
void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {10,10};                                      //1i
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}
//========================================================================
void initSnake(snake_t *head[], size_t size, int x, int y,int i)
{
    head[i]    = (snake_t*)malloc(sizeof(snake_t));
    tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->tail     = tail; // прикрепляем к голове хвост
    head[i]->tsize    = size+1;
    head[i]->controls = default_controls[i];
    //head[i]->controls = default_controls[0];
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if(head->x <= 0) // Циклическое движение, чтобы не
            // уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        if(head->x >= max_x)                                            //1i
            head->x = 0;                                                //1i
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if(head->y <= MIN_Y)                                            //1i
            head->y = max_y;                                            //1i
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if(head->y >= max_y)                                            //1i
            head->y = MIN_Y-1;                                          //1i
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

//========================================================================
//Проверка того, является ли какое-то из зерен съеденным,               //3i 23.03.25
_Bool haveEat(struct snake_t *head, struct food f[])
{
    for(size_t i=0; i<SEED_NUMBER; i++)
    {
        if( ((head->x) == f[i].x) && ((head->y) == f[i].y)  && (f[i].enable == 1) )
        {
            f[i].enable = 0;
            return 1;
        }
    }
    return 0;
}

/*
 Увеличение хвоста на 1 элемент
 */

void addTail(struct snake_t *head)                                      //3i 23.03.25
{
    if ( (head->tsize) <= MAX_TAIL_SIZE )
    {
        head->tsize++;
    }
}
//========================================================================
int checkDirection(snake_t* snake, int32_t key)                         //3i 23.03.25
{
    if ((key == snake->controls.down) && ((snake->direction != UP)))
    {
        return 1;
    }
    else if ((key == snake->controls.up) && ((snake->direction != DOWN)))
    {
        return 1;
    }
    else if ((key == snake->controls.right) && ((snake->direction != LEFT)))
    {
        return 1;
    }
    else if ((key == snake->controls.left) && ((snake->direction != RIGHT)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Вынести тело цикла while из int main() в отдельную функцию update
//и посмотреть, как изменится профилирование
void update(struct snake_t *head, struct food f[], const int32_t key)
{
    clock_t begin = clock();
    go(head);
    goTail(head);
    if (checkDirection(head,key))
    {
        changeDirection(head, key);
    }
    refreshFood(food, SEED_NUMBER);// Обновляем еду
    if (haveEat(head,food))
    {
        addTail(head);
    }
    refresh();//Обновление экрана, вывели кадр анимации
    while ((double)(clock() - begin)/CLOCKS_PER_SEC<DELAY)
    {}
}
//========================================================================

_Bool isCrush(snake_t * snake)                                          //3i 23.03.25 скопировали из 1i фун cannibal
{
    int max_x=0, max_y=0;
    if (snake->tsize < 4)                                                //попасть головой на хвост можно только начиная с 4го элемента хвоста от головы
    {
        return 0;
    }
    for(size_t i=3; i<=(snake->tsize-1); i++)
    {
        if( ((snake->x) == snake->tail[i].x) && ((snake->y) == snake->tail[i].y))
        {

            getmaxyx(stdscr, max_y, max_x);
            mvprintw(max_y/2,max_x/2-5,"GAME OVER!");                   //2i 11.03.25 выводим надпись по центру
            refresh();
            sleep(2);                                                   //задержка отрисовки
            return 1;
        }
    }
    return 0;
}
//========================================================================
//при положительной проверке деактивируем плохое зерно, и по алгоритму оно сразу же будет переназначенно, как если бы его съела змейка
void repairSeed(struct food f[], size_t nfood, struct snake_t *head)    //3i 23.03.25
{
    for( size_t i=0; i<head->tsize; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            if( (f[j].enable == 1) && (head->tail[i].x == f[j].x ) && (head->tail[i].y == f[j].y ) )
            {
                f[j].enable = 0;
                Deb badSeedS++;
            }
        }
    for( size_t i=0; i<nfood; i++ )
        for( size_t j=0; j<nfood; j++ )
        {
            if (i==j) continue; //убираем проверку зерна самим с собой
            if( (f[i].enable == 1) && (f[j].enable == 1) && ( f[i].x == f[j].x) && (f[i].y == f[j].y))
            {
                f[j].enable = 0; //убираем одно из зерен
                Deb badSeedF++;
            }
        }
}



int main()
{
    //========================================================================
    snake_t* snakes[PLAYERS];
    for (int i = 0; i < PLAYERS; i++)
        initSnake(snakes,START_TAIL_SIZE,10+i*10,10+i*10,i);
    //========================================================================

    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows for control. Press 'F10' for EXIT");
    timeout(0);    //Отключаем таймаут после нажатия клавиши в цикле
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);// Кладем зерна
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        for (int i = 0; i < PLAYERS; i++)
        {
            update(snakes[i], food, key_pressed);
            if(isCrush(snakes[i]))
            {
                key_pressed = STOP_GAME;
            }
            repairSeed(food, SEED_NUMBER, snakes[i]);
        }
    }
    for (int i = 0; i < PLAYERS; i++)
    {
        //printExit(snakes[i]);
        free(snakes[i]->tail);
        free(snakes[i]);
    }

    endwin(); // Завершаем режим curses mod

    Deb printf("\n");
    Deb printf("BadSeedSnake = %d BadSeedFood = %d\n",badSeedS,badSeedF);
    return 0;
}
