declare i32 @putchar(i32)

declare i32 @getchar(i32)

@a = global i32 2
@b = global i32 2
@c = global double 2.00
@d = global i32 2
define i32 @main(){
  %1 = add i32 32, 0
  %2 = call i32 @putchar(i32 %1)
  %3 = add i32 32, 0
  %4 = call i32 @putchar(i32 %3)
  %5 = add i32 97, 0
  %6 = call i32 @putchar(i32 %5)
  %7 = add i32 32, 0
  %8 = call i32 @putchar(i32 %7)
  %9 = add i32 98, 0
  %10 = call i32 @putchar(i32 %9)
  ret i32 0
}
