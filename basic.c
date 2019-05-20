// to include necessary global variables
extern int x, y, x_point, y_point, x_loc, y_loc;
extern float game_time;
#define XSIGN '!'
#define YSIGN '?'
#define WALLSIGN '#'

// declarations
int get_number();

int randint(int upper,int lower); // Generates a random integer between upper and lower

void make(char board[], char what, int n); // Puts n number of a given symbol in empty spaces within the board

void addpoint(char who,int increase);

// Three following functions are used to make and print game board

void row_maker(char board[], int length, int start, char sth); // Makes a row of sths started at block start in borad as long as length (Just called in board_maker())

void board_maker(char board[]); // The main board maker which is called at the first of the game

void glance(char board[], int n); // Shows the map at the beginning of the game for n seconds

void print_screen(char board[]); // Prints the game board with all stuff

void print_score(); // Prints players' scores and game remaining time


int get_number(){
    int num, c;
    num = 0;
    while((c = getchar()) != '\n')
        num = num*10 + ( c - '0' );
    return num;
}

int randint(int upper,int lower){
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
        if (what == XSIGN) {
            x_loc = place;
        }
        else if (what == YSIGN) {
            y_loc = place;
        }
        i++;
    }
}

void addpoint(char who,int increase){
    if (who == XSIGN)
        x_point = x_point + increase;
    else if (who == YSIGN)
        y_point = y_point + increase;
}

void row_maker(char board[], int length, int start, char sth) {
    int i = 0;
    while (i < length) {
        board[start + i] = sth;
        i++;
    }
}

void board_maker(char board[]) {
    row_maker(board, x + 2, 0, WALLSIGN);
    int i = 0;
    int pointer = x + 2;
    while (i < y) {
        board[pointer] = WALLSIGN;
        pointer++;
        row_maker(board, x, pointer, ' ');
        pointer = pointer + x;
        board[pointer] = WALLSIGN;
        pointer++;
        i++;
    }
    row_maker(board, x + 2, pointer, WALLSIGN);
    pointer = pointer + x + 3;
    board[pointer] = '\0';
}

void glance(char board[], int n) {
    int temp_time2;
    while (n != 0) {
        temp_time2 = clock();
        system("cls");
        printf("\n Take a look  at the map... %d\n\n", n);
        n--;
        print_screen(board);
        while (clock() < temp_time2 + 1000);
    }
}
void print_screen(char board[]) {
    int i = 0;
    while (board[i] != '\0') {
        printf("%.*s\n", x + 2, board + i);
        i += x + 2;
    }
}

void print_score() {
    printf("\nRemaining time: %0.1f\nPlayer 1 score: %d\nPlayer 2 score: %d\n", game_time, x_point, y_point);
}

