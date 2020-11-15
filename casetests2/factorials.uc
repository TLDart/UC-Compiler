// Iterative Version ( most common )
int factorial(int number) {
    int answer = 1;
    while (number != 0) {
        answer = answer * number;
        number = number - 1;
    }
    return answer;
} 

/*
    Recursive Implementation (Tipical implementation)
*/

int recursive_factorial(int number) {
    if (num == 0) {
        return 1;
    }   
    return number * recursive_factorial(number);
}

/*
    Tail Recursive Version 
    >>> Which means that the recursive call is the last thing executed by the function.
*/

int tail_recursive_factorial(int number, int k){
    if (number == 0) {
        return 1;
	}
    return factorial(number - 1, k * number);
}

void i_have_no_life_xD(void){
    putchar('#');
    putchar('#');
    putchar('\t');
    putchar('F');
    putchar('A');
    putchar('C');
    putchar('T');
    putchar('O');
    putchar('R');
    putchar('I');
    putchar('A');
    putchar('L');
    putchar('S');
    putchar('#');
    putchar('#');
    putchar('\t');
    putchar('\n');
}  

int ctoi(char c) {
	if (c >= '0' && c <= '9'){
        return c - '0';
	}
}

int main(void) {

    i_have_no_life_xD();

    int i = ctoi(getchar());
    
    recursive_factorial(i);
    tail_recursive_factorial(i);
    factorial(i);

    return 0;
}
