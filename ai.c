
#define COIN '.'
#define GEM 'F'
#define YSIGN '?'
extern int y_loc,x,y;
char choice[2];

char prev;

void ai(char board[],int rad){
    if(board[y_loc-x-2]=='F')
        choice[0]='i';
    else if(board[y_loc-1]=='F')
        choice[0]='j';
    else if(board[y_loc+x+2]=='F')
        choice[0]='k';
    else if(board[y_loc+1]=='F')
        choice[0]='l';
    else if(board[y_loc-x-1]=='F')
        choice[0]='i';
    else if(board[y_loc-x-1]=='F')
        choice[0]='i';
    else if(board[y_loc+x+1]=='F')
        choice[0]='k';
    else if(board[y_loc+x+3]=='F')
        choice[0]='k';

    else if(board[y_loc-x-2]=='.')
        choice[0]='i';
    else if(board[y_loc-1]=='.')
        choice[0]='j';
    else if(board[y_loc+x+2]=='.')
        choice[0]='k';
    else if(board[y_loc+1]=='.')
        choice[0]='l';
    else if(board[y_loc-x-3]=='.')
        choice[0]='i';
    else if(board[y_loc-x-1]=='.')
        choice[0]='i';
    else if(board[y_loc+x+1]=='.')
        choice[0]='k';
    else if(board[y_loc+x+3]=='.')
        choice[0]='k';

    else if(board[y_loc-x-2]!='#'&&prev!='k')
        choice[0]='i';
    else if(board[y_loc-1]!='#'&&prev!='l')
        choice[0]='j';
    else if(board[y_loc+x+2]!='#'&&prev!='i')
        choice[0]='k';
    else if(board[y_loc-x]!='#'&&prev!='j')
        choice[0]='l';

    choice[1]='\0';
    movep(YSIGN,choice,board);
    prev=choice[0];
}
