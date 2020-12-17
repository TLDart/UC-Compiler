declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca double
  %1 = fadd double 3.2, 0.0
  store double %1, double* %a
  br label %label1

label1:
  %2 = load double, double* %a
  %3 = fadd double 12.3, 0.0
  %4 = fcmp olt double %2, %3
  %5 = zext i1 %4 to i32
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %label2, label %label3

label2:
  %7 = add i32 102, 0
  %8 = call i32 @putchar(i32 %7)
  %9 = load double, double* %a
  %10 = load double, double* %a
  %11 = fadd double 3.2, 0.0
  %12 = fadd double %10, %11
  store double %12, double* %a
  br label %label1

label3:
  ret i32 0
}
