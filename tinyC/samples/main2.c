int get_sum(int a, int b){
    return a + b;
}

int get_cien(){
    return 100;
}

int main(){
    int x[10];
    int y;
    char c;

    y = 32767;
    c = 'a';
    // printf("~y = %d", ~y);
    y=10;
    // printf("y = %d", y);
    // printf("++y = %d", ++y);
    // printf("y = %d", y);
    // printf("--y = %d", --y);
    // printf("y = %d", y);
    // printf("y++ = %d", y++);
    // printf("y = %d", y);
    // printf("y-- = %d", y--);
    // printf("y = %d", y);

    printf("ternary_true 10 = %d", 1 == 1 ? 10 : 0);
    printf("ternary_false 0 = %d", 1 != 1 ? 10 : 0);
    printf("complex ternary 0 = %d", 1 == 1 ? (5 != 5 ? 10 : 0) : 0);
    printf("complex ternary 10 = %d", 1 == 1 ? (5 == 5 ? 10 : 0) : 0);

    y = (int)'a';
    printf("y = %d", y);
    c = (char)97;
    printf("c = %c", c);

    printf("hola[0] = %c", "hola"[0]);
    printf("hola[1] = %c", "hola"[1]);
    printf("hola[2] = %c", "hola"[2]);
    printf("hola[3] = %c", "hola"[3]);

    x[0] = 0;
    x[1] = 1;
    x[4] = 4;
    x[5] = 5;
    x[6] = 6;
    x[8] = 8;
    x[9] = 9;

    printf("x[0] = %d", x[0]);

    printf("sizeof(int) = %d sizeof(x) = %d sizeof(c) = %d", sizeof(int), sizeof(x), sizeof(c));

    printf("100 = %d", get_cien());
    printf("1+2 = %d", 1+2);
    printf("2-1 = %d", 2-1);
    printf("100*20 = %d", 100*20);
    printf("22/2 = %d", 22/2);
    printf("5 mod 2 = %d", 5%2);

    printf("1+2 = %d", get_sum(1,2));

    printf("1&&1 = %d", 1 && 1);
    printf("1||1 = %d", 1 || 1);

    printf("1&&0 = %d", 1 && 0);
    printf("1||0 = %d", 1 || 0);

    printf("1>0 = %d", 1 > 0);
    printf("1>=0 = %d", 1 >= 0);
    printf("1<0 = %d", 1 < 0);
    printf("1<=0 = %d", 1 <= 0);
    printf("1==0 = %d", 1 == 0);
    printf("1!=0 = %d", 1 != 0);
    printf("!(1!=0) = %d", !(1 != 0));

}