declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca double
  %1 = fadd double 3.2, 0.0
  store double %1, double* %a
  %2 = add i32 98, 0
  %3 = call i32 @putchar(i32 %2)
  %4 = add i32 98, 0
  %5 = call i32 @putchar(i32 %4)
  %6 = add i32 98, 0
  %7 = call i32 @putchar(i32 %6)
  %8 = add i32 98, 0
  %9 = call i32 @putchar(i32 %8)
  %10 = load double, double* %a
  %11 = add i32 2, 0
  %12 = sitofp i32 %11 to double
  %13 = fcmp olt double %10, %12
  %14 = zext i1 %13 to i32
  %15 = icmp eq i32 %14, 1
  br i1 %15, label %label1, label %label2

label1:
  %16 = add i32 98, 0
  %17 = call i32 @putchar(i32 %16)
  %18 = add i32 100, 0
  %19 = call i32 @putchar(i32 %18)
  %20 = add i32 99, 0
  %21 = call i32 @putchar(i32 %20)
  %22 = add i32 10, 0
  %23 = call i32 @putchar(i32 %22)
  br label %label3

label2:
  %24 = add i32 99, 0
  %25 = call i32 @putchar(i32 %24)
  %26 = add i32 97, 0
  %27 = call i32 @putchar(i32 %26)
  %28 = add i32 98, 0
  %29 = call i32 @putchar(i32 %28)
  %30 = add i32 10, 0
  %31 = call i32 @putchar(i32 %30)
  br label %label3

label3:
  ret i32 0
}
