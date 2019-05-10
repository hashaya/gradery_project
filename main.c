#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "move.h"

#define XSIGN '!'
#define YSIGN '?'

int mode,temp_time,x_point,y_point,x,y,x_direction,y_direction;
float game_time;
char moves[201],board[10000];
int main(void){
    char c;
    int i;
    game_time=60.0;
    printf(""); // First game message
    mode = get_number();
    system("cls");
    printf(""); // Game guide
    print_screen();
    if (mode == 0) {
        while(time != 0){ // Main loop for two player mode
                i=0;
                temp_time = clock();
                if(_kbhit()&&i<=200){
                    c=_getch();
                    moves[i]=c;
                    i++;
                }
                moves[i]='\n';
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                print_screen();
        }
    }
    if (mode == 1) {
        while(time != 0){ // Main loop for AI
                temp_time = clock();
                i=0;
                if(_kbhit()&&i<=200){
                    c=_getch();
                    moves[i]=c;
                    i++;
                }
                moves[i]='\n';
                movep(XSIGN, moves, board);
                ai(board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                print_screen();
        }
    }
    system("cls");
    if (x_point > y_point){
        printf("Player 1 won the game!\n");
    }
    if (x_point < y_point){
        printf("Player 2 won the game!\n");
    }
    if (x_point == y_point){
        printf("Draw!\n");
    }
    return 0;
}

