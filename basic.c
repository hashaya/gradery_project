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

void make(char board[], char what, int n){ //puts n number of a given symbol in empty spaces within the board
    int place, i;
    i = 0;
    while (i < n) {
        for(place=randint((x*y)-(x+1), (x+1));board[place]!=' ';place=randint((x*y)-(x+1), (x+1)));
        board[place]=what;
        i++;
    }
}

void addpoint(char who,int increase){

}
