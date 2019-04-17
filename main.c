#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(int ms){ //delays process for ms milliseconds
    int start;
    start=clock();
    while (clock()<start+ms){;}//wastes time here
}

void addpoint(char who,int increase){

}

int findindex(char board[], char target){
    int i;
    for(i=0;board[i]!=target;i++){
        if board[i]=='\0'
            return -1; //error 404: not found
    }
    return i;

}

void changeindex(char board[],int from,int to){
    char what;
    if(board[to]!='#'){
        what=board[from];
        board[from]=' ';
        if(board[to]=='.')
            addpoint(what,1);
        else if(board[to]=='F')
            addpoint(what,5);
        if((board[to]=='T')&&(findindex(board,'T')!=-1))
            board[to]=what;
            changeindex(board,board[to],findindex(board,'T'));
        else
            board[to]=what;
    }
}

void movep(char control[],char board[],int x){
    int i,index;
    for(i=0;control[i]!='\0';i++){
        if(input[i]=='w'){
            index=findindex(board,'!');
            changeindex(board,index,index-x);
        }
        else if(input[i]=='a'){
            index=findindex(board,'!');
            changeindex(board,index,index-1);
        }
    }
}

int main(){
    return 0;
}
/*
int getnum(void){
    int num,c;
    num=0;
    while((c=getchar())!='\n')
        num=num*10+(c-'0');
    return num;
}
void getgame(int statarray[]){
    statarray[0]=getnum(); //play mode
    statarray[1]=getnum(); //time
    statarray[2]=getnum(); //length
    statarray[3]=getnum(); //width
    //statarray[4]=getnum(); //coins
    //statarray[5]=getnum(); //gems
    //statarray[6]=getnum(); //blocks
    //statarray[7]=getnum(); //portals
    //statarray[8]=getnum(); //difficulty
}
void setpos(int pd,int dmax){
    for(pd=rand();pd>dmax;)
        pd=rand();
}
int main(void){
    int gamestats[10];
    getgame(gamestats);
    int i,is,p1x,p1y,p2x,p2y;/*
    setpos(p1x,gamestats[2]);
    setpos(p1y,gamestats[3]);
    setpos(p2x,gamestats[2]);
    setpos(p2y,gamestats[3]);
    while(p2x!=p1x&&p2y!=p1y){
        setpos(p2x,gamestats[2]);
        setpos(p2y,gamestats[3]);
    }
    for(i=0;i!=gamestats[2];i+=1)
        printf("#");
    for(i=0;i!=(gamestats[3]-2);i+=1){
        printf("\n#");
        for(is=0;is!=(gamestats[2]-2);is+=1)
            if(p1y==i&&p1x==is)
               printf("1");
            else if(p2y==i&&p2x==is)
                printf("2");
            else printf(" ");
        printf("#");
    }
    printf("\n");
    for(i=0;i!=gamestats[2];i+=1)
        printf("#");
    return 0;
}

int splitcontrols(char input[]){ //now that i wrote it, feels absolutely useless :(
    int start,i,p1i,p2i;         //edit: yes it IS useless :((
    char p1[40],p2[40];
    p1i=0;p2i=0;
    start=clock();
    for(i=0;input[i]!='\0';i++){
        if((input[i]=='w')||(input[i]=='a')||(input[i]=='s')||(input[i]=='d')){
            p1[p1i]=input[i];
            p1i++;
        }
        else if((input[i]=='i')||(input[i]=='j')||(input[i]=='k')||(input[i]=='l')){
            p2[p2i]=input[i];
            p2i++;
        }
    }
}
*/
