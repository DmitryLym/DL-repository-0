#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  1                                                        //1i_05.03.25 достаточно 1
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

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

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t= {10,10}; 										//1i_05.03.25 убрано затирание символа U
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
    head->controls = default_controls;
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
        if(head->x >= max_x)							   				//1i_05.03.25
            head->x = 0;												//1i_05.03.25
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if(head->y <= MIN_Y) 							   				 //1i_05.03.25
            head->y = max_y;											//1i_05.03.25
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if(head->y >= max_y) 							    			//1i_05.03.25
            head->y = MIN_Y-1;											//1i_05.03.25 зачем-то нужно вычесть 1 иначе голова выходит на строчку ниже при переходе нижней границы
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key) 					//1i_05.03.25
//не позволяем змейке разворачиваться саму в себя
{
    if ((key == snake->controls.down) && ((snake->direction != UP)))    		//1i_05.03.25
        snake->direction = DOWN;
    else if ((key == snake->controls.up) && ((snake->direction != DOWN)))		//1i_05.03.25
        snake->direction = UP;
    else if ((key == snake->controls.right) && ((snake->direction != LEFT)))	//1i_05.03.25
        snake->direction = RIGHT;
    else if ((key == snake->controls.left) && ((snake->direction != RIGHT)))	//1i_05.03.25
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
    head->tail[0].y = head->y;
    head->tail[0].x = head->x;

}

char cannibal(struct snake_t *head)										//1i_07.03.25 проверка попадания голов на хвост
{
    char bite =0;
    if (head->tsize < 4)												//попасть головой на хвост можно только начиная с 4го элемента хвоста от головы
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

void delay(double sec)													//1i_07.03.25 новая задержка
{
clock_t begin = clock();
while((double)(clock() - begin)/CLOCKS_PER_SEC<sec);
}


int main()
{
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake,START_TAIL_SIZE+30,10,10);							// удлиним хвост для проверки
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();            // Отключаем echo() режим при вызове getch
    curs_set(FALSE);    //Отключаем курсор
    mvprintw(0, 0,"Use arrows for control. Press 'F10' for EXIT");
	timeout(0);    	//Отключаем таймаут после нажатия клавиши в цикле
    int key_pressed=0;
    while( key_pressed != STOP_GAME )
    {
        key_pressed = getch(); // Считываем клавишу
        go(snake);
        goTail(snake);
        delay(0.1);														// Задержка при отрисовке
        changeDirection(snake, key_pressed);
        if (cannibal(snake)) 											//1i_07.03.25
        {
            mvprintw(15,60,"GAME OVER!");
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
