/*******************************************
 * File: ArithOperators.py
 * A test program for arithmethic operators
 *******************************************/
#include "RelationalOperators.h"
void main() {
    int x, y;
    
    srand(time(0));

    x = 5;//rand() % 100 + 1;
    y = 7;//rand() % 100 + 1;

    printf("X = %d, Y = %d\n", x, y);

    printf("Add %d\n", x + y);
    printf("Sub %d\n", x - y);
    printf("Mul %d\n", x * y);
    printf("Div %d\n", x / y);
    printf("Mod %d\n", x % y);
    printf("Mod %d\n", 'H');
}