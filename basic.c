int get_number(){
    int num,c;
    num=0;
    while((c=getchar()) != '\n')
        num = num*10 + ( c - '0' );
    return num;
}

int randint(int upper,int lower){ //generates a random integer between upper and lower
    int num;
    num=(rand()%(upper-lower+1))+lower;
    return num;
}

void make(char board[],char what){ //puts a given symbol in an empty space within the board
    int place;
    for(place=randint((x*y)-(x+1), (x+1));board[place]!=' ';place=randint((x*y)-(x+1), (x+1)));
    board[place]=what;
}

void addpoint(char who,int increase){

}
