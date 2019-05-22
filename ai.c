//gets board, calls movep

#define COIN '.'
#define GEM 'F'
#define YSIGN '?'
extern int y_loc,x,y;
char prev='\0';
char choice[2];

int randchoose(void){
    int num;
    num=(rand()%(4));
    return num;
}

void ai(char board[],int rad){
    int rc;
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

    else if(board[y_loc-x-2]!='#'&&board[y_loc-x-2]!='B'&&prev=='i')
        choice[0]=prev;
    else if(board[y_loc-1]!='#'&&board[y_loc-1]!='B'&&prev=='j')
        choice[0]=prev;
    else if(board[y_loc+x+2]!='#'&&board[y_loc+x+2]!='B'&&prev=='k')
        choice[0]=prev;
    else if(board[y_loc+1]!='#'&&board[y_loc+1]!='B'&&prev=='l')
        choice[0]=prev;

    else{
        rc=randchoose();
        if(rc==0)
            choice[0]='i';
        else if(rc==1)
            choice[0]='j';
        else if(rc==2)
            choice[0]='k';
        else if(rc==3)
            choice[0]='l';
    }
    choice[1]='\0';
    prev=choice[0];
    movep(YSIGN,choice,board);
}
