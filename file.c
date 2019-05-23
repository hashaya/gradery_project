#include <stdio.h>
extern int x, y, number_of_dots;
extern float game_time;
extern char board[];
// declarations
void read1();

void read2();

void read1() {
    FILE *my_file;
    my_file = fopen("settings.txt", "r");
    if (my_file == NULL){
        printf("File Reading Error");
        getchar();
        exit(0);
    }
    fscanf(my_file, "%d %d", &y, &x);
    fclose(my_file);
}

void read2() {
    FILE *my_file;
    my_file = fopen("settings.txt", "r");
    if (my_file == NULL){
        printf("File Reading Error");
        getchar();
        exit(0);
    }
    int temp, block_x, block_y;
    fscanf(my_file, "%d %d %f %d", &temp, &temp, &game_time, &number_of_dots);
    while(fscanf(my_file, "%d %d", &block_x, &block_y) != EOF) {
        constant_maker(board, x, y, block_x, block_y, 'B');
    }
    fclose(my_file);
}


void record(char winner[],char loser[],int wp,int lp){
    FILE *my_file;
    my_file=fopen("leaderboard.txt","a+");
    fprintf(my_file,"%s  %d - %d  %s\n",winner,wp,lp,loser);
    fclose(my_file);
}

int getscore(char p1[],char p2[],char whose[]){
    int res,d1,d2;
    FILE *my_file;
    my_file=fopen("leaderboard.txt","r");
    if(fscanf(my_file,"%s  %d - %d  %s\n",p1,&d1,&d2,p2))
        if(strcmp(p1,whose)==0)
            res=d1;
        else
            res=d2;
    else if(fscanf(my_file,"%s  %d - %d  %s\n",p2,&d1,&d2,p1))
        if(strcmp(p2,whose)==0)
            res=d1;
        else
            res=d2;
    else
        res=0;
    fclose(my_file);
    return res;
}
