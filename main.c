#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIGN '!'
#define YSIGN '?'

int mode, temp_time, x_point, y_point, x, y, x_direction, y_direction,i;
float game_time;
char moves[201], board[10000];
int main(){
    game_time = 60.0;
    i=0;
    printf(""); // First game messege
    mode = get_number();
    system("cls");
    printf(""); // Game guide
    print_screen();
    if (mode == 0) {
        while(time != 0){ // Main loop for two player mode
                temp_time = clock();
                if(_kbhit()){
                    _getch()=moves[i];
                    i++;
                }
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                print_screen();
    if (mode == 1) {
        while(time != 0){ // Main loop for AI
                temp_time = clock();
                if(_kbhit()){
                    _getch()=moves[i];
                    i++;
                }
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
}

