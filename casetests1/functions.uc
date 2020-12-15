void testFunction(char i) {
  while (i <= 'Z') {
    putchar(i);
    i = i + 1;
  }
}

int main(void) {
  testFunction('A');
  return 0;
}
