
int a(void) {
    int a = 2;
    return a;
}

int aa(void) {
    return 2;
}

short b(void) {
    short a;
    return a;
}

short bb(void) {
    return 3;
}

char c(void) {
    char a;
    return a;
}

char cc(void) {
    return 'A';
}

void d(void) {
    return;
}

double e(void) {
    double d;
    return d;
}

double ee(void) {
    return 1.2;
}

void f(int a, short b, char c, int d, double e) {
    return;
}

char global_char = '\123';
short global_short = 10;
int global_int = 14;
double global_double = 1.4;

char global_a;
short global_b;
int global_c;
double global_d;

void g(void) {
    char a;
    a = 'A';

    short b;
    b = 2;

    int c;
    c = 1;

    double d;
    d = 1.2;
}

void h(void) {
    char e;
    e = global_char;

    short f_to_pay_respects;
    f_to_pay_respects = global_short;

    int g;
    g = global_int;

    double h;
    h = global_double;

    double i;
    i = global_double;
    return;
}

void i(void) {
    char a;
    short b;
    int c;
    double d;

    char j;
    j = a;

    short l;
    l = b;

    int m;
    m = c;

    double n;
    n = d;
}

void j(void) {
    global_char = 'B';

    global_int = 10;

    global_short = 12;

    global_double = 1.3;
}

void l(void) {
    char a;
    short b;
    int c;
    double d;

    global_char = a;

    global_int = b;

    global_short = c;

    global_double = d;
}

void m(void) {
    global_char = global_a;

    global_int = global_b;

    global_short = global_c;

    global_double = global_d;
}

void downcast_store(void) {
    char a;
    short b;
    int c;
    double d;

    d = a;
    d = b;
    d = c;

    global_double = global_a;
    global_double = global_b;
    global_double = global_c;
}

int aaa = 12;

void downcast_declaration(void) {
    char a;
    short b;
    int c;
    double d;

    double d1 = a;
    double d2 = b;
    double d3 = c;
    double d4 = d;
}

int main(void) {
    return 0;
}
