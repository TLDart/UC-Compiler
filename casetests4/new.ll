declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %a = alloca i32
  %1 = add i32 2, 0
  %2 = sub i32 0, %1
  store i32 %2, i32* %a
  %3 = load i32, i32* %a
  %4 = add i32 2, 0
  %5 = sub i32 0, %4
  %6 = icmp eq i32 %3, %5
  %7 = zext i1 %6 to i32
  %8 = icmp eq i32 %7, 1
  br i1 %8, label %label1, label %label2

label1:
  %9 = add i32 97, 0
  %10 = call i32 @putchar(i32 %9)
  br label %label3

label2:
  br label %label3

label3:
  ret i32 0
}
