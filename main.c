#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIGN '!'
#define YSIGN '?'

int mode,temp_time,x_point,y_point,x,y,x_direction,y_direction;
float game_time;
char moves[200],board[10000];
int main(void){
    char c;
    int i;
    game_time = 60.0;
    x_point = 0;
    y_point = 0;
    printf("\n Hello\n\n Choose your game mode:\n\n 0: Player1 vs Player2\n 1: Player1 vs Computer\n"); // First game message
    mode = getchar();
    system("cls");
    if (mode != 1) {
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n Player 2: I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press Enter to enter the game...");
        board_maker(board);
        getchar();
        print_screen();
        while(game_time != 0){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                if(_kbhit()&&i<=200){
                    c=_getch();
                    moves[i]=c;
                    i++;
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                system("cls");
                print_screen();
        }
    }
    else {
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n\n Q(quit the game)\n\n Press Enter to enter the game...");
        board_maker(board);
        getchar();
        print_screen();
        while(game_time != 0){ // Main loop for AI
                temp_time = clock();
                // get start point
                i = 0;
                if(_kbhit()&&i<=200){
                    c=_getch();
                    moves[i]=c;
                    i++;
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                ai(board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                system("cls");
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

