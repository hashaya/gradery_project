// to include necessary global variables
extern int x, y, x_direction, y_direction;
#define XSIGN '!'
#define YSIGN '?'

// declarations
int findindex(char board[], char target);

void teleport(char board[], char what);

void changeindex(char board[],int from,int to);

void movep(char player_sign, char control[],char board[]);


int findindex(char board[], char target){
    int i;
    for(i=0; board[i] != target; i++){
        if (board[i] == '\0')
            return -1; //error 404: not found
    }
    return i;

}

void teleport(char board[], char what){
    int to=findindex(board,'T');
    int from=findindex(board,what);
    board[from]=' ';
    board[to]=what;
}

void changeindex(char board[],int from,int to){
    char what;
    if (to == 1)
        to = from + 1;
    else if (to == 2)
        to = from - x;
    else if (to == 3)
        to = from - 1;
    else if (to == 4)
        to = from + x;

    if((board[to]!='#')&&(board[to]!='B')){
        what=board[from];
        board[from]=' ';
        if(board[to]=='.')
            addpoint(what,1);
        else if(board[to]=='F')
            addpoint(what,5);
        if(board[to]=='T'){
            board[to]=what;
            teleport(board,what);
        }
        else
            board[to]=what;
    }
}

void movep(char player_sign, char control[],char board[]){
    int i, index;
    if (player_sign == XSIGN) {
        for(i = 0; control[i] != '\0'; i++){
            if(control[i] == 'w'){
                index = findindex(board, XSIGN);
                x_direction = 2;
            }
            if(control[i] == 'a'){
                index = findindex(board, XSIGN);
                x_direction = 3;
            }
            if(control[i] == 's'){
                index = findindex(board, XSIGN);
                x_direction = 4;
            }
            if(control[i] == 'd'){
                index = findindex(board, XSIGN);
                x_direction = 1;
            }

        }
        changeindex(board, index, x_direction);
    }

    else if (player_sign == YSIGN) {
        for(i = 0; control[i] != '\0'; i++){
            if(control[i] == 'i'){
                index = findindex(board, YSIGN);
                y_direction = 2;
            }
            if(control[i] == 'j'){
                index = findindex(board, YSIGN);
                y_direction = 3;
            }
            if(control[i] == 'k'){
                index = findindex(board, YSIGN);
                y_direction = 4;
            }
            if(control[i] == 'l'){
                index = findindex(board, YSIGN);
                y_direction = 1;
            }
        }
        changeindex(board, index, y_direction);
    }
}
