extern int x,y,x_direction,y_direction,x_loc,y_loc;
#define XSIGN '!'
#define YSIGN '?'

int xfront[16],yfront[16];
int frontof(char what,int dir,char board[]){
    if(what==XSIGN){
        if(dir=='w'){
            xfront[16]=x_loc-(x+2);
            xfront[13]=x_loc-2*(x+2)-1;
            xfront[14]=x_loc-2*(x+2);
            xfront[15]=x_loc-2*(x+2)+1;
            xfront[10]=x_loc-3*(x+2)-1;
            xfront[11]=x_loc-3*(x+2);
            xfront[12]=x_loc-3*(x+2)+1;
            xfront[5]=x_loc-4*(x+2)-2;
            xfront[6]=x_loc-4*(x+2)-1;
            xfront[7]=x_loc-4*(x+2);
            xfront[8]=x_loc-4*(x+2)+1;
            xfront[9]=x_loc-4*(x+2)+2;
            xfront[0]=x_loc-5*(x+2)-2;
            xfront[1]=x_loc-5*(x+2)-1;
            xfront[2]=x_loc-5*(x+2);
            xfront[3]=x_loc-5*(x+2)+1;
            xfront[4]=x_loc-5*(x+2)+2;
        }else if(dir=='a'){
            xfront[10]=x_loc-1;
            xfront[5]=x_loc-2-(x+2);
            xfront[9]=x_loc-2;
            xfront[14]=x_loc-2+(x+2);
            xfront[4]=x_loc-3-(x+2);
            xfront[8]=x_loc-3;
            xfront[13]=x_loc-3+(x+2);
            xfront[1]=x_loc-4-2*(x+2);
            xfront[3]=x_loc-4-(x+2);
            xfront[7]=x_loc-4;
            xfront[12]=x_loc-4+(x+2);
            xfront[16]=x_loc-4+2*(x+2);
            xfront[0]=x_loc-5-2*(x+2);
            xfront[2]=x_loc-5-(x+2);
            xfront[6]=x_loc-5;
            xfront[11]=x_loc-5+(x+2);
            xfront[15]=x_loc-5+2*(x+2);
        }else if(dir=='s'){
            xfront[0]=x_loc+(x+2);
            xfront[1]=x_loc+2*(x+2)-1;
            xfront[2]=x_loc+2*(x+2);
            xfront[3]=x_loc+2*(x+2)+1;
            xfront[4]=x_loc+3*(x+2)-1;
            xfront[5]=x_loc+3*(x+2);
            xfront[6]=x_loc+3*(x+2)+1;
            xfront[7]=x_loc+4*(x+2)-2;
            xfront[8]=x_loc+4*(x+2)-1;
            xfront[9]=x_loc+4*(x+2);
            xfront[10]=x_loc+4*(x+2)+1;
            xfront[11]=x_loc+4*(x+2)+2;
            xfront[12]=x_loc+5*(x+2)-2;
            xfront[13]=x_loc+5*(x+2)-1;
            xfront[14]=x_loc+5*(x+2);
            xfront[15]=x_loc+5*(x+2)+1;
            xfront[16]=x_loc+5*(x+2)+2;
        }else if(dir=='d'){
            xfront[6]=x_loc+1;
            xfront[11]=x_loc+2-(x+2);
            xfront[7]=x_loc+2;
            xfront[2]=x_loc+2+(x+2);
            xfront[12]=x_loc+3-(x+2);
            xfront[8]=x_loc+3;
            xfront[3]=x_loc+3+(x+2);
            xfront[15]=x_loc+4-2*(x+2);
            xfront[13]=x_loc+4-(x+2);
            xfront[9]=x_loc+4;
            xfront[4]=x_loc+4+(x+2);
            xfront[0]=x_loc+4+2*(x+2);
            xfront[16]=x_loc+5-2*(x+2);
            xfront[14]=x_loc+5-(x+2);
            xfront[10]=x_loc+5;
            xfront[5]=x_loc+5+(x+2);
            xfront[1]=x_loc+5+2*(x+2);
    }
    else{
        if(dir=='i'){
            yfront[16]=y_loc-(x+2);
            yfront[13]=y_loc-2*(x+2)-1;
            yfront[14]=y_loc-2*(x+2);
            yfront[15]=y_loc-2*(x+2)+1;
            yfront[10]=y_loc-3*(x+2)-1;
            yfront[11]=y_loc-3*(x+2);
            yfront[12]=y_loc-3*(x+2)+1;
            yfront[5]=y_loc-4*(x+2)-2;
            yfront[6]=y_loc-4*(x+2)-1;
            yfront[7]=y_loc-4*(x+2);
            yfront[8]=y_loc-4*(x+2)+1;
            yfront[9]=y_loc-4*(x+2)+2;
            yfront[0]=y_loc-5*(x+2)-2;
            yfront[1]=y_loc-5*(x+2)-1;
            yfront[2]=y_loc-5*(x+2);
            yfront[3]=y_loc-5*(x+2)+1;
            yfront[4]=y_loc-5*(x+2)+2;
        }else if(dir=='j'){
            yfront[10]=y_loc-1;
            yfront[5]=y_loc-2-(x+2);
            yfront[9]=y_loc-2;
            yfront[14]=y_loc-2+(x+2);
            yfront[4]=y_loc-3-(x+2);
            yfront[8]=y_loc-3;
            yfront[13]=y_loc-3+(x+2);
            yfront[1]=y_loc-4-2*(x+2);
            yfront[3]=y_loc-4-(x+2);
            yfront[7]=y_loc-4;
            yfront[12]=y_loc-4+(x+2);
            yfront[16]=y_loc-4+2*(x+2);
            yfront[0]=y_loc-5-2*(x+2);
            yfront[2]=y_loc-5-(x+2);
            yfront[6]=y_loc-5;
            yfront[11]=y_loc-5+(x+2);
            yfront[15]=y_loc-5+2*(x+2);
        }else if(dir=='k'){
            yfront[0]=y_loc+(x+2);
            yfront[1]=y_loc+2*(x+2)-1;
            yfront[2]=y_loc+2*(x+2);
            yfront[3]=y_loc+2*(x+2)+1;
            yfront[4]=y_loc+3*(x+2)-1;
            yfront[5]=y_loc+3*(x+2);
            yfront[6]=y_loc+3*(x+2)+1;
            yfront[7]=y_loc+4*(x+2)-2;
            yfront[8]=y_loc+4*(x+2)-1;
            yfront[9]=y_loc+4*(x+2);
            yfront[10]=y_loc+4*(x+2)+1;
            yfront[11]=y_loc+4*(x+2)+2;
            yfront[12]=y_loc+5*(x+2)-2;
            yfront[13]=y_loc+5*(x+2)-1;
            yfront[14]=y_loc+5*(x+2);
            yfront[15]=y_loc+5*(x+2)+1;
            yfront[16]=y_loc+5*(x+2)+2;
        }else if(dir=='l'){
            yfront[6]=y_loc+1;
            yfront[11]=y_loc+2-(x+2);
            yfront[7]=y_loc+2;
            yfront[2]=y_loc+2+(x+2);
            yfront[12]=y_loc+3-(x+2);
            yfront[8]=y_loc+3;
            yfront[3]=y_loc+3+(x+2);
            yfront[15]=y_loc+4-2*(x+2);
            yfront[13]=y_loc+4-(x+2);
            yfront[9]=y_loc+4;
            yfront[4]=y_loc+4+(x+2);
            yfront[0]=y_loc+4+2*(x+2);
            yfront[16]=y_loc+5-2*(x+2);
            yfront[14]=y_loc+5-(x+2);
            yfront[10]=y_loc+5;
            yfront[5]=y_loc+5+(x+2);
            yfront[1]=y_loc+5+2*(x+2);
        }
    }
}

void print_screen_probe(char board[]){
    int i,k,xf,yf,pd;
    k=1;
    frontof(XSIGN,x_direction,board);
    frontof(YSIGN,y_direction,board);
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
            
        }
    }
}
