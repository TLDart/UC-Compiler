declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %i = alloca i32
  %1 = add i32 65, 0
  store i32 %1, i32* %i
  br label %label1

label1:
  %2 = load i32, i32* %i
  %3 = add i32 90, 0
  %4 = icmp sle i32 %2, %3
  %5 = zext i1 %4 to i32
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %label2, label %label3

label2:
  %7 = load i32, i32* %i
  %8 = call i32 @putchar(i32 %7)
  %9 = load i32, i32* %i
  %10 = load i32, i32* %i
  %11 = add i32 1, 0
  %12 = add i32 %10, %11
  store i32 %12, i32* %i
  br label %label1

label3:
  %13 = add i32 0, 0
  ret i32 %13
  ret i32 0
}
