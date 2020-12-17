declare i32 @putchar(i32)

declare i32 @getchar(i32)

@i = global i32 8
define i32 @main(){
  %a = alloca double
  %1 = add i32 2, 0
  %2 = sitofp i32 %1 to double
  store double %2, double* %a
  %b = alloca i32
  %3 = add i32 65, 0
  store i32 %3, i32* %b
  %c = alloca i32
  %4 = add i32 66, 0
  store i32 %4, i32* %c
  %d = alloca i32
  %5 = add i32 122, 0
  store i32 %5, i32* %d
  %e = alloca double
  %6 = load i32, i32* %b
  %7 = sitofp i32 %6 to double
  store double %7, double* %e
  %f = alloca double
  %8 = load i32, i32* %c
  %9 = sitofp i32 %8 to double
  store double %9, double* %f
  %g = alloca double
  %10 = load i32, i32* %d
  %11 = sitofp i32 %10 to double
  store double %11, double* %g
  %h = alloca double
  %12 = add i32 2, 0
  %13 = sitofp i32 %12 to double
  store double %13, double* %h
  %i = alloca double
  %14 = fadd double 2.1, 0.0
  store double %14, double* %i
  %j = alloca i32
  %15 = add i32 1, 0
  store i32 %15, i32* %j
  %l = alloca i32
  %16 = add i32 97, 0
  store i32 %16, i32* %l
  %k = alloca double
  %17 = load i32, i32* %j
  %18 = sitofp i32 %17 to double
  store double %18, double* %k
  %19 = load i32, i32* %b
  %20 = call i32 @putchar(i32 %19)
  %21 = load i32, i32* %c
  %22 = call i32 @putchar(i32 %21)
  %23 = load i32, i32* %d
  %24 = call i32 @putchar(i32 %23)
  %25 = load i32, i32* %b
  %26 = load i32, i32* %c
  store i32 %26, i32* %b
  %27 = load i32, i32* %c
  %28 = add i32 108, 0
  store i32 %28, i32* %c
  %29 = load double, double* %e
  %30 = add i32 2, 0
  %31 = sitofp i32 %30 to double
  store double %31, double* %e
  %32 = load double, double* %h
  %33 = fadd double 4.3, 0.0
  store double %33, double* %h
  %34 = load double, double* %k
  %35 = load i32, i32* %l
  %36 = sitofp i32 %35 to double
  store double %36, double* %k
  %37 = load i32, i32* %b
  %38 = call i32 @putchar(i32 %37)
  %39 = load i32, i32* %c
  %40 = call i32 @putchar(i32 %39)
  %41 = load i32, i32* %l
  %42 = call i32 @putchar(i32 %41)
  ret i32 0
}
