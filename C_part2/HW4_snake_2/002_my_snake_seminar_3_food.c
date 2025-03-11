#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  1                                                        //1i достаточео 1й строки
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10,SEED_NUMBER=3};

enum {CONTROLS=3};                                                      //2i 11.03.25 кол-во вариантов управления

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
};

struct control_buttons default_controls[CONTROLS];                      //2i 11.03.25 объявление массива управления

void initcontrol_buttons(struct control_buttons c[],size_t size)        //2i 11.03.25 функция инициализации управления
{
    struct control_buttons key = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};
    struct control_buttons buk = {'s', 'w', 'a', 'd'};
    struct control_buttons Buk = {'S', 'W', 'A', 'D'};

    switch (size)                                                       // в данной реализации break преднамеренно опущен
    {
    case 3:
        c[2] = Buk;
    case 2:
        c[1] = buk;
    case 1:
        c[0] = key;
    }
}


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
    struct control_buttons controls[CONTROLS];                          //2i 11.03.25
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

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    for (int i = 0; i < CONTROLS; i++)
    {
    head->controls[i] = default_controls[i];                            //2i 11.03.25
    }
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

void changeDirection(struct snake_t* snake, const int32_t key)                  //1i+2i 11.03.25
//не позволяем змейке разворачиваться саму в себя + анализируем коды управления ленивой логикой
{
    if ((key == snake->controls[0].down || key == snake->controls[1].down || key == snake->controls[2].down ) && ((snake->direction != UP)))             //1i+2i 11.03.25
        snake->direction = DOWN;
    else if ((key == snake->controls[0].up || key == snake->controls[1].up || key == snake->controls[2].up ) && ((snake->direction != DOWN)))            //1i+2i 11.03.25
        snake->direction = UP;
    else if ((key == snake->controls[0].right || key == snake->controls[1].right || key == snake->controls[2].right ) && ((snake->direction != LEFT)))   //1i+2i 11.03.25
        snake->direction = RIGHT;
    else if ((key == snake->controls[0].left || key == snake->controls[1].left || key == snake->controls[2].left ) && ((snake->direction != RIGHT)))     //1i+2i 11.03.25
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

char cannibal(struct snake_t *head)                                     //1i
{
    char bite =0;
    if (head->tsize < 4)                                                //попасть головой на хвост можно только начиная с 4го элемента хвоста от головы
    {
        return bite;
    }
    for(size_t i=3; i<=(head->tsize-1); i++)
    {
        if( ((head->x) == head->tail[i].x) && ((head->y) == head->tail[i].y))
        {
            bite =1;
            return bite;
        }
    }
    return bite;
}

void delay(double sec)                                                  //1i новая задержка
{
    clock_t begin = clock();
    while((double)(clock() - begin)/CLOCKS_PER_SEC<sec);
}

int main()
{
    initcontrol_buttons(default_controls,CONTROLS);                     //2i 11.03.25 инициализация управления

    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE+10,10,10);                          // удлиним хвост для проверки

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
        go(snake);
        goTail(snake);
        delay(0.1);                                                     // Задержка при отрисовке
        refreshFood(food, SEED_NUMBER);// Обновляем еду
        changeDirection(snake, key_pressed);
        if (cannibal(snake))                                            //1i
        {
            int max_x=0, max_y=0;
            getmaxyx(stdscr, max_y, max_x);
            mvprintw(max_y/2,max_x/2-5,"GAME OVER!");                   //2i 11.03.25 выводим надпись по центру
            refresh();
            delay(5);
            key_pressed = STOP_GAME;
        }
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}
