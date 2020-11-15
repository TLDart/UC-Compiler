/*
COMMENT
*/
// COMMENT AS WELL
int check_your_priorities(int a, int b, int c, int d) {
    return a + (b * (- d / c + 3) * d + c) + d;
}

char block(char a, char b) {
    if (a < b){
        a = a - 1;
        return a;
    } else {
        b = b - 1;
        return b;
    }
}

char not_block(char a, char b) {
    if (weird_char(a, b) < b)
        return a;
    else
        return b;
}

double check_your_decimal_places(double a, double b){
    double PI = 3.14;
    return a - b * PI;
}
