extern int x,y,x_direction,y_direction,x_loc,y_loc;
#define XSIGN '!'
#define YSIGN '?'

int xfront[9],yfront[9];
int frontof(int dir,char board[]){
    if(dir=='w'){
        xfront[0]=x_loc-(x+2);
        xfront[1]=x_loc-2*(x+2)-1;
        xfront[2]=x_loc-2*(x+2);
        xfront[3]=x_loc-2*(x+2)+1;
        xfront[4]=x_loc-3*(x+2)-2;
        xfront[5]=x_loc-3*(x+2)-1;
        xfront[6]=x_loc-3*(x+2);
        xfront[7]=x_loc-3*(x+2)+1;
        xfront[8]=x_loc-3*(x+2)+2;
    }else if(dir=='a'){
        xfront[0]=x_loc-1;
        xfront[1]=x_loc-2-x-2;
        xfront[2]=x_loc-2;
        xfront[3]=x_loc-2+(x+2);
        xfront[4]=x_loc-3-2*(x+2);
        xfront[5]=x_loc-3-(x+2);
        xfront[6]=x_loc-3;
        xfront[7]=x_loc-3+(x+2);
        xfront[8]=x_loc-3+2*(x+2);
    }else if(dir=='s'){
        xfront[0]=x_loc+(x+2);
        xfront[1]=x_loc+2*(x+2)-1;
        xfront[2]=x_loc+2*(x+2);
        xfront[3]=x_loc+2*(x+2)+1;
        xfront[4]=x_loc+3*(x+2)-2;
        xfront[5]=x_loc+3*(x+2)-1;
        xfront[6]=x_loc+3*(x+2);
        xfront[7]=x_loc+3*(x+2)+1;
        xfront[8]=x_loc+3*(x+2)+2;
    }else if(dir=='d'){
        xfront[0]=x_loc+1;
        xfront[1]=x_loc+2-x-2;
        xfront[2]=x_loc+2;
        xfront[3]=x_loc+2+(x+2);
        xfront[4]=x_loc+3-2*(x+2);
        xfront[5]=x_loc+3-(x+2);
        xfront[6]=x_loc+3;
        xfront[7]=x_loc+3+(x+2);
        xfront[8]=x_loc+3+2*(x+2);
    }else if(dir=='i'){
        yfront[0]=y_loc-(x+2);
        yfront[1]=y_loc-2*(x+2)-1;
        yfront[2]=y_loc-2*(x+2);
        yfront[3]=y_loc-2*(x+2)+1;
        yfront[4]=y_loc-3*(x+2)-2;
        yfront[5]=y_loc-3*(x+2)-1;
        yfront[6]=y_loc-3*(x+2);
        yfront[7]=y_loc-3*(x+2)+1;
        yfront[8]=y_loc-3*(x+2)+2;
    }else if(dir=='j'){
        yfront[0]=y_loc-1;
        yfront[1]=y_loc-2-x-2;
        yfront[2]=y_loc-2;
        yfront[3]=y_loc-2+(x+2);
        yfront[4]=y_loc-3-2*(x+2);
        yfront[5]=y_loc-3-(x+2);
        yfront[6]=y_loc-3;
        yfront[7]=y_loc-3+(x+2);
        yfront[8]=y_loc-3+2*(x+2);
    }else if(dir=='k'){
        yfront[0]=y_loc+(x+2);
        yfront[1]=y_loc+2*(x+2)-1;
        yfront[2]=y_loc+2*(x+2);
        yfront[3]=y_loc+2*(x+2)+1;
        yfront[4]=y_loc+3*(x+2)-2;
        yfront[5]=y_loc+3*(x+2)-1;
        yfront[6]=y_loc+3*(x+2);
        yfront[7]=y_loc+3*(x+2)+1;
        yfront[8]=y_loc+3*(x+2)+2;
    }else if(dir=='l'){
        yfront[0]=y_loc+1;
        yfront[1]=y_loc+2-x-2;
        yfront[2]=y_loc+2;
        yfront[3]=y_loc+2+(x+2);
        yfront[4]=y_loc+3-2*(x+2);
        yfront[5]=y_loc+3-(x+2);
        yfront[6]=y_loc+3;
        yfront[7]=y_loc+3+(x+2);
        yfront[8]=y_loc+3+2*(x+2);
    }
}

void print_screen_probe(char board[]){
    int i,k,xf,yf,pd;
    k=1;
    frontof(x_direction,board);
    frontof(y_direction,board);
    for(i=0;board[i]!='\0';i++,pd=0){
        if(board[i]=='#'){
            printf("#");
            if(i==k*(x+2)-1){
                printf("\n");
                k++;
            }
        }else if(board[i]==XSIGN||board[i]==YSIGN)
            printf("%c",board[i]);
        else{
            for(xf=0,yf=0;xf<10;xf++,yf++){
                if(i==xfront[xf]||i==yfront[yf]){
                    printf("%c",board[i]);
                    pd=1;
                    break;
                }
            }
            if(pd==0)
                printf(" ");
        }
    }
}
