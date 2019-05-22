// to include necessary global variables
extern int x, y, x_direction, y_direction, x_loc, y_loc;
#define XSIGN '!'
#define YSIGN '?'
#define WALLSIGN '#'

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
    if (what == XSIGN)
        x_loc = to;
    else if (what == YSIGN)
        y_loc = to;
    make(board, 'T', 2);
}

void changeindex(char board[],int from,int to){
    char what;
    if (to == '\0')
        return;
    if (to == 'd' || to == 'l')
        to = from + 1;
    else if (to == 'w' || to == 'i')
        to = from - x - 2;
    else if (to == 'a' || to == 'j')
        to = from - 1;
    else if (to == 's' || to == 'k')
        to = from + x + 2;

    if(board[to] != 'B' && board[to] != WALLSIGN && to != x_loc && to != y_loc){
        what=board[from];
        board[from]=' ';
        if(board[to]=='.')
            addpoint(what,1);
        else if(board[to]=='F')
            addpoint(what,5);
        else if(board[to]=='T'){
            board[to]=what;
            teleport(board,what);
            return;
        }
        board[to]=what;
        if (what == XSIGN)
            x_loc = to;
        else if (what == YSIGN)
            y_loc = to;
    }
}

void movep(char player_sign, char control[],char board[]){
    int i, index;
    if (player_sign == XSIGN) {
        for(i = 0; control[i] != '\0'; i++){
            if (control[i] == 'd' || control[i] == 'w' || control[i] == 'a' || control[i] == 's')
                x_direction = control[i];
        }
        changeindex(board, x_loc, x_direction);
    }

    else if (player_sign == YSIGN) {
        for(i = 0; control[i] != '\0'; i++){
            if (control[i] == 'l' || control[i] == 'i' || control[i] == 'j' || control[i] == 'k')
                y_direction = control[i];
        }
        changeindex(board, y_loc, y_direction);
    }
}
