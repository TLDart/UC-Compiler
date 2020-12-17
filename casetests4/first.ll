declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca i32
  %1 = add i32 65, 0
  store i32 %1, i32* %a
  %2 = load i32, i32* %a
  %3 = call i32 @putchar(i32 %2)
  %4 = add i32 92, 0
  %5 = call i32 @putchar(i32 %4)
  ret i32 0
}
