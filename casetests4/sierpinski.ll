declare i32 @putchar(i32)

declare i32 @getchar(i32)

define i32 @main(){
  %i = alloca i32
  %1 = add i32 0, 0
  store i32 %1, i32* %i
  %j = alloca i32
  store i32 0, i32* %j
  br label %label1

label1:
  %2 = load i32, i32* %i
  %3 = add i32 32, 0
  %4 = icmp slt i32 %2, %3
  %5 = zext i1 %4 to i32
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %label2, label %label3

label2:
  %7 = load i32, i32* %j
  %8 = add i32 0, 0
  store i32 %8, i32* %j
  br label %label4

label4:
  %9 = load i32, i32* %j
  %10 = add i32 32, 0
  %11 = icmp slt i32 %9, %10
  %12 = zext i1 %11 to i32
  %13 = icmp eq i32 %12, 1
  br i1 %13, label %label5, label %label6

label5:
  %14 = load i32, i32* %i
  %15 = load i32, i32* %j
  %16 = or i32 %14, %15
  %17 = icmp eq i32 %16, 1
  br i1 %17, label %label7, label %label8

label7:
  %18 = add i32 32, 0
  %19 = call i32 @putchar(i32 %18)
  br label %label9

label8:
  %20 = add i32 43, 0
  %21 = call i32 @putchar(i32 %20)
  br label %label9

label9:
  %22 = load i32, i32* %j
  %23 = load i32, i32* %j
  %24 = add i32 1, 0
  %25 = add i32 %23, %24
  store i32 %25, i32* %j
  br label %label4

label6:
  %26 = load i32, i32* %i
  %27 = load i32, i32* %i
  %28 = add i32 1, 0
  %29 = add i32 %27, %28
  store i32 %29, i32* %i
  %30 = add i32 10, 0
  %31 = call i32 @putchar(i32 %30)
  br label %label1

label3:
  %32 = add i32 0, 0
  ret i32 %32
  ret i32 0
}
