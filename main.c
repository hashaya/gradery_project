#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIGN '!'
#define YSIGN '?'

int mode, temp_time, x_point, y_point, x, y, x_direction, y_direction, x_loc, y_loc, number_of_dots;
float game_time;
char moves[10], board[12000];
int main(void){
    srand(time(NULL));
    char c;
    int i;
    printf("\n Choose your game mode:\n\n 1: Player1 vs Player2\n 2: Player1 vs Computer\n 3: Probe (Two Players)\n\n 0: Advanced options\n"); // First game message
    mode = get_number();
    // Reading from file and making game board
    read1();
    board_maker(board, x, y);
    read2();
    make(board, '.', number_of_dots);
    make(board, 'T', 2);
    make(board, 'F', 1);
    make(board, XSIGN, 1);
    make(board, YSIGN, 1);
    // Game starting settings
    x_point = 0;
    y_point = 0;
    x_direction = '\0';
    y_direction = '\0';
    system("cls");
    if (mode == 1) {
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n Player 2: I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press any key to enter the game...");
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + 200) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='Q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen(board);
                print_score();
        }
    }
    else if (mode == 2){
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n\n Q(quit the game)\n\n Press Enter to enter the game...");
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + 200) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='Q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                ai(board,1);
                game_time = game_time - 0.2;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen(board);
                print_score();
        }
    }
    else if (mode == 3) {
        printf("\n Player 1: W(up), S(down), D(right), A(left)\n Player 2: I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press any key to enter the game...");
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + 200) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='Q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - 0.2;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen_probe(board);
                print_score();
        }
    }
    else if (mode == 0) {

    }
    else{
        printf("Mode not applicable, try again.\n");
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
            exit(0);
        if(c=='r'){
            system("cls");
            main();
        }
    }
    return 0;
}
