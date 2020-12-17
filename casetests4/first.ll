declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca double
  %1 = add i32 3, 0
  store double %1, double* %a
  %2 = load i32, i32* %a
  %3 = add i32 2, 0
  %4 = sitofp i32 %3 to double
  %5 = fcmp olt double %2, %4
  %6 = zext i1 %5 to i32
  %7 = icmp eq i32 %6, 1
  br i1 %7, label %label1, label %label2

label1:
  %8 = add i32 98, 0
  %9 = call i32 @putchar(i32 %8)
  br label %label3

label2:
  %10 = add i32 99, 0
  %11 = call i32 @putchar(i32 %10)
  br label %label3

label3:
  ret i32 0
}
