declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca double
  %1 = add i32 2, 0
  %2 = sitofp i32 %1 to double
  store double %2, double* %a
  ret i32 0
}
