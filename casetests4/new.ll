declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca i32
  %1 = fadd double 2.1, 0.0
  %2 = fcmp une double %1, 0.0
  %3 = xor i1 %2, true
  %4 = zext i1 %3 to i32
  store i32 %4, i32* %a
  %b = alloca double
  %5 = fadd double 2.1, 0.0
  %6 = fneg double %5
  store double %6, double* %b
  %7 = load double, double* %b
  %8 = fadd double 2.1, 0.0
  %9 = fneg double %8
  %10 = fcmp oeq double %7, %9
  %11 = zext i1 %10 to i32
  %12 = icmp eq i32 %11, 1
  br i1 %12, label %label1, label %label2

label1:
  %13 = add i32 97, 0
  %14 = call i32 @putchar(i32 %13)
  br label %label3

label2:
  br label %label3

label3:
  ret i32 0
}
