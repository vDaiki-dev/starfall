#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_STARS 120

typedef struct {
    int x, y;
    int speed;
} Star;

int main() {
    srand(time(NULL));
    initscr();
    curs_set(0);
    noecho();
    timeout(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);

    Star stars[MAX_STARS];
    for(int i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % COLS;
        stars[i].y = rand() % LINES;
        stars[i].speed = (rand() % 3) + 1;
    }

    while(1) {
        int ch = getch();
        if(ch == 'q') break;

        clear();
        for(int i = 0; i < MAX_STARS; i++) {
            attron(COLOR_PAIR(1));
            mvprintw(stars[i].y, stars[i].x, "*");
            
            if (stars[i].y - 1 >= 0 && stars[i].x + 1 < COLS) {
                attron(COLOR_PAIR(2));
                mvprintw(stars[i].y - 1, stars[i].x + 1, "'");
            }
            
            stars[i].y += stars[i].speed;
            stars[i].x -= stars[i].speed;
            
            if(stars[i].y > LINES || stars[i].x < 0) {
                stars[i].y = 0;
                stars[i].x = rand() % (COLS + (COLS/2));
            }
        }
        refresh();
        usleep(30000);
    }
    endwin();
    return 0;
}
