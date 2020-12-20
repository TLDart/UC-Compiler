int a = 1;
int b = 2;
int func(int a, int b){
  int c = a + b;
  a = 1;
  b = 2;
  if (c != (a+b)){
    putchar('M');
  } else {
    putchar('N');
  }
  
  putchar('_');
  if (a == b - 1){
    putchar('K');
  } else{
    putchar('L');
  }
  putchar('\\');
  putchar(' ');
  putchar('\n');
  putchar('\t');
  putchar('\'');
  putchar('\"');
  putchar('\000');
  // putchar('011');
  putchar('\n');
  putchar('\11');

}

int power(int base, int exp){
  int aux = 1;
  while(exp){
    aux = aux * base;
    exp = exp - 1;
  }
  return aux;
}


int binaryToDecimal(int binarynum)
{
    int decimalnum = 0, temp = 0, remainder;
    while (binarynum!=0)
    {
        remainder = binarynum % 10;
        binarynum = binarynum / 10;
        decimalnum = decimalnum + remainder*power(2,temp);
        temp = temp + 1;
    }
    return decimalnum;
}



int add(int a, int b){
  return a + b;
}

void return_void(int a, int b){
  return ;
}

int main(void){
  int a = 1;
  int b = 2;
  if((a+1) == b){
    putchar('A');
  } else {
    putchar('B');
  }

  a = 4;
  b = 3;
  if((a+1) == b){
    putchar('C');
  } else {
    putchar('D');
  }

  char c = 1;
  char d = 2;

  if((a+1) == (c-(-1*(-1*(-1)))) && !!(b-1 == d-1)){
    putchar('E');
  } else {
    putchar('F');
  }

  short e = 'A';
  short f = 'B';

  if (!(!e == 'A' - 'B') ){
    putchar('G');
  } else {
    putchar('H');
  }

  int i = 5;
  while(i){
    putchar('I');
    i = i - 1;
  }

  char a1;
  short a2;
  int a3;
  double a4;

  a1 = 'A';
  a2 = 2;
  a3 = 3;
  a4 = 'B';

  putchar((a1 == 'A') + '0');
  putchar((a2 == 2) + '0');
  putchar((a3 == 2) + '0');
  putchar((a4 == 'B') + '0');

  putchar('0' + func(10,10));

  putchar('0'+ 1 + add(2,2));
  
  putchar('0' + 4%2);
  putchar('\n');

  int result = binaryToDecimal(1001);
  putchar('0' + result);
  if (result == 9){
    putchar('D');
  } else {
    putchar('F');
  }
  
  putchar('\n');
  return 0;

  i = 5;
  while(i){
    putchar('J');
    i = i - 1;
  }
  
}

