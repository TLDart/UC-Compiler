declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca i32
  %1 = add i32 72, 0
  store i32 %1, i32* %a
  %b = alloca i32
  %2 = add i32 101, 0
  store i32 %2, i32* %b
  %3 = load i32, i32* %a
  %4 = call i32 @putchar(i32 %3)
  %5 = load i32, i32* %b
  %6 = call i32 @putchar(i32 %5)
  %7 = add i32 108, 0
  %8 = call i32 @putchar(i32 %7)
  %9 = add i32 108, 0
  %10 = call i32 @putchar(i32 %9)
  %11 = add i32 111, 0
  %12 = call i32 @putchar(i32 %11)
  %c = alloca i32
  %13 = add i32 32, 0
  store i32 %13, i32* %c
  %d = alloca i32
  %14 = add i32 87, 0
  store i32 %14, i32* %d
  %15 = load i32, i32* %c
  %16 = call i32 @putchar(i32 %15)
  %17 = load i32, i32* %d
  %18 = call i32 @putchar(i32 %17)
  %e = alloca i32
  %19 = add i32 111, 0
  store i32 %19, i32* %e
  %20 = load i32, i32* %e
  %21 = call i32 @putchar(i32 %20)
  %22 = add i32 114, 0
  %23 = call i32 @putchar(i32 %22)
  %24 = add i32 108, 0
  %25 = call i32 @putchar(i32 %24)
  %26 = add i32 100, 0
  %27 = call i32 @putchar(i32 %26)
  %f = alloca i32
  %28 = add i32 10, 0
  store i32 %28, i32* %f
  %29 = load i32, i32* %f
  %30 = call i32 @putchar(i32 %29)
  ret i32 0
}
