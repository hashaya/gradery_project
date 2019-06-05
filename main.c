#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define XSIGN '!'
#define YSIGN '?'

int mode, temp_time, x_point, y_point, x, y, x_direction, y_direction, x_loc, y_loc, number_of_dots, speed = 5, delay;
float game_time, time_reduction;
char moves[10], board[12000], x_name[30], y_name[30];
int main(void){
    hidecursor();
    srand(time(NULL));
    system("cls");
    char c;
    int i;
    printf("\n Choose your game mode:\n\n 1: Player1 vs Player2\n 2: Player1 vs Computer\n 3: Probe (Two Players)\n\n 0: Advanced options\n "); // First game message
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
    delay = speed * 40;
    time_reduction = (float)delay/1000.0;
    system("cls");
    if (mode == 1) {
        x_name[0] = y_name[0] = '\0';
        get_player_name(1, "");
        get_player_name(2, "");
        printf("\n %s(!): W(up), S(down), D(right), A(left)\n %s(?): I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press any key to enter the game...", x_name, y_name);
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + delay) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - time_reduction;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen(board);
                print_score();
        }
    }
    else if (mode == 2){
        x_name[0] = '\0';
        get_player_name(1, "");
        get_player_name(2, "Computer");
        printf("\n %s(!): W(up), S(down), D(right), A(left)\n\n Q(quit the game)\n\n Press Enter to enter the game...", x_name);
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + delay) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                ai(board,1);
                game_time = game_time - time_reduction;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen(board);
                print_score();
        }
    }
    else if (mode == 3) {
        x_name[0] = y_name[0] = '\0';
        get_player_name(1, "");
        get_player_name(2, "");
        printf("\n %s(!): W(up), S(down), D(right), A(left)\n %s(?): I(up), K(down), L(right), J(left)\n\n Q(quit the game)\n\n Press any key to enter the game...", x_name, y_name);
        _getch();
        system("cls");
        glance(board, 5);
        while(game_time > 0.1){ // Main loop for two player mode
                temp_time = clock();
                i = 0;
                // get start point
                while (clock() < temp_time + delay) {
                    if(_kbhit() && i < 10){
                        c = _getch();
                        if(c=='q')
                            exit(0);
                        moves[i] = c;
                        i++;
                    }
                }
                moves[i]='\0';
                // get end point
                movep(XSIGN, moves, board);
                movep(YSIGN, moves, board);
                game_time = game_time - time_reduction;
                //while (clock() < temp_time + 0.2);
                system("cls");
                print_screen_probe(board);
                print_score();
        }
    }
    else if (mode == 0) {
        int c = 0;
        while (c == 0) {
            system("cls");
            printf("\n You can change the game speed\n Choose a number from 1 to 10 (1 fastest mode & 10 slowest mode)\n Default: 5\n\n ");
            c = get_number();
            system("cls");
            if (c >= 1 && c <= 10){
                speed = c;
                printf("\n Speed successfully changed. Press any key to continue.");
                getchar();
                main();
            }
            else {
                printf("\n Invalid speed. Press any key to try again...");
                c = 0;
                getchar();
            }
        }
    }
    else{
        printf("Mode not applicable, try again.\n");
        main();
    }
    system("cls");
    if (x_point > y_point){
        printf("\n %s's score: %d\n %s's score: %d\n\n %s won the game!\n", x_name, x_point, y_name, y_point, x_name);
        record(x_name,y_name,getscore(x_name,y_name,x_name)+1,getscore(x_name,y_name,y_name));
    }
    else if (x_point < y_point){
        printf("\n %s's score: %d\n %s's score: %d\n\n %s won the game!\n", x_name, x_point, y_name, y_point, y_name);
        record(y_name,x_name,getscore(x_name,y_name,y_name)+1,getscore(x_name,y_name,x_name));
    }
    else if (x_point == y_point){
        printf("\n %s's score: %d\n %s's score: %d\n\n Draw!\n", x_name, x_point, y_name, y_point);
        record(x_name,y_name,getscore(x_name,y_name,x_name),getscore(x_name,y_name,y_name));
    }
    printf("\n Press q to quit or r to play again.\n");
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
