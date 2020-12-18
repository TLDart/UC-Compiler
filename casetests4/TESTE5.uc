int start = 5;

int foo(int value){
    if (value == 0){
        value = value - 1;
        return foo(value);
    }
    return 'J';
}

int main(void){
    putchar(foo(start));
    int start_inside = 2;
    putchar(foo(start_inside));
    return 0;
}