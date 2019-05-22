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
    if (my_file == NULL)
        printf("Error");
    fscanf(my_file, "%d %d", &y, &x);
    fclose(my_file);
}

void read2() {
    FILE *my_file;
    my_file = fopen("settings.txt", "r");
    if (my_file == NULL)
        printf("Error");
    int temp, block_x, block_y;
    fscanf(my_file, "%d %d %f %d", &temp, &temp, &game_time, &number_of_dots);
    while(fscanf(my_file, "%d %d", &block_x, &block_y) != EOF) {
        constant_maker(board, x, y, block_x, block_y, 'B');
    }
    fclose(my_file);
}
