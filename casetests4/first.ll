declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca double
  %1 = add i32 2, 0
  %2 = sitofp i32 %1 to double
  store double %2, double* %a
  %3 = load double, double* %a
  %4 = add i32 4, 0
  %5 = sitofp i32 %4 to double
  store double %5, double* %a
  %6 = load double, double* %a
  %7 = add i32 4, 0
  %8 = sitofp i32 %7 to double
  %9 = fcmp oeq double %6, %8
  %10 = zext i1 %9 to i32
  %11 = icmp eq i32 %10, 1
  br i1 %11, label %label1, label %label2

label1:
  %12 = add i32 102, 0
  %13 = call i32 @putchar(i32 %12)
  br label %label3

label2:
  br label %label3

label3:
  ret i32 0
}
