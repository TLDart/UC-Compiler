int cc;

void f(void) {
    cc = 'Y';
}

int error_in_C_problem(void) {
    char a, b;
    int c;
    a = 10;
    b = -5;
    c = 0;

    putchar(027 * 01365 + 'A');
    putchar(!((!a || !b || !c) && -2 && (!b || !a)) + 'A');
    putchar((a && (b = b + 1) && c || (b = b + 4) && (a = a - 5) || 1 || (c = -1)) + 'A');
    putchar(a + 'A');
    return 0;
}

int error_in_D_problem(void) {
    int a = 5;
    putchar(a);
    int b = 3;
    putchar(b);
    a = a + 1;
    putchar(a);
    a = 2 * a;
    putchar(a);
    int c = (b = b + 1, a = a + b, b = 2 * b) - 5;
    putchar(a);
    putchar(b);
    putchar(c);
    return 0;
}

char nand(char x, char y) {
    return !(x && y);
}

char nor(char x, char y) {
    return !(x || y);
}

int random_tests(void) {
    cc = 'F';
    double x = 1.2;
    double y = 1.5;
    double z = 1.5 / 1.2;

    int g = 0 & 12;
    int zz = 65;
    int c = +(+zz);
    int d = -(-zz);
    int e = 4 | 1 * 2;

    putchar(g);

    int a = 67;
    if (f(), a = 65, 1) {
        putchar(a);
        putchar('X');
        putchar(cc);
    } else {
        putchar(a);
        if ((1, 2, 31)) {
            putchar('B');
        }
    }
    putchar(a);
    return 0;
}

int main(void) {

    error_in_C_problem();
    putchar('\n');
    error_in_D_problem();
    putchar('\n');
    // error in E problem;
    nand('A', 'B');
    nor('A', 'B');

    // Other
    random_tests();
    return 0;
}