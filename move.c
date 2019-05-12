#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIGN '!'
#define YSIGN '?'

int mode,temp_time,x_point = 0,y_point = 0,x = 100,y = 30,x_direction,y_direction;
float game_time;
char moves[200], board[10000];
int main(void){
    char c;
    int i;
    game_time = 10;
    printf("Hello\n\n Choose your game mode:\n\n 0: Player1 vs Player2\n 1: Player1 vs Computer\n"); // First game message
    mode = get_number();
    system("cls");
    if (mode == 0) {
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n Player 2: I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press Enter to enter the game...");
        board_maker(board);
        getchar();
        make(board, 'B', 10);
        make(board, 'T', 2);
        make(board, 'F', 1);
        make(board, '.', 700);
        make(board, XSIGN, 1);
        make(board, YSIGN, 1);
        print_screen();
        getchar();
        while(game_time >= 0){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + 200) {
                    if(_kbhit()&&i<=200){
                        c=_getch();
                        moves[i]=c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                while (clock() < temp_time + 0.2);
                system("cls");
                print_screen(board);
        }
    }
    else if (mode == 1){
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
                //ai(board);
                game_time = game_time - 0.2;
                system("cls");
                print_screen(board);
        }
    }
    else{
        printf("Mode not applicable, try again");
        main();
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
    printf("\nPress q to quit or r to play again.\n");
    while((c=_getch())!='q'||c!='r'){
        if(c=='q')
            return 0;
        if(c=='r'){
            system("cls");
            main();
        }
    }
    return 0;
}
