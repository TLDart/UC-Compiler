; ModuleID = '../tests/input/tests.c'
source_filename = "../tests/input/tests.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@global_char = global i8 83, align 1
@global_short = global i16 10, align 2
@global_int = global i32 14, align 4
@global_double = global double 1.400000e+00, align 8
@global_a = common global i8 0, align 1
@global_b = common global i16 0, align 2
@global_c = common global i32 0, align 4
@global_d = common global double 0.000000e+00, align 8
@aaa = global i32 12, align 4

; Function Attrs: nounwind uwtable
define i32 @a() #0 {
  %1 = alloca i32, align 4
  store i32 2, i32* %1, align 4
  %2 = load i32, i32* %1, align 4
  ret i32 %2
}

; Function Attrs: nounwind uwtable
define i32 @aa() #0 {
  ret i32 2
}

; Function Attrs: nounwind uwtable
define signext i16 @b() #0 {
  %1 = alloca i16, align 2
  %2 = load i16, i16* %1, align 2
  ret i16 %2
}

; Function Attrs: nounwind uwtable
define signext i16 @bb() #0 {
  ret i16 3
}

; Function Attrs: nounwind uwtable
define signext i8 @c() #0 {
  %1 = alloca i8, align 1
  %2 = load i8, i8* %1, align 1
  ret i8 %2
}

; Function Attrs: nounwind uwtable
define signext i8 @cc() #0 {
  ret i8 65
}

; Function Attrs: nounwind uwtable
define void @d() #0 {
  ret void
}

; Function Attrs: nounwind uwtable
define double @e() #0 {
  %1 = alloca double, align 8
  %2 = load double, double* %1, align 8
  ret double %2
}

; Function Attrs: nounwind uwtable
define double @ee() #0 {
  ret double 1.200000e+00
}

; Function Attrs: nounwind uwtable
define void @f(i32, i16 signext, i8 signext, i32, double) #0 {
  %6 = alloca i32, align 4
  %7 = alloca i16, align 2
  %8 = alloca i8, align 1
  %9 = alloca i32, align 4
  %10 = alloca double, align 8
  store i32 %0, i32* %6, align 4
  store i16 %1, i16* %7, align 2
  store i8 %2, i8* %8, align 1
  store i32 %3, i32* %9, align 4
  store double %4, double* %10, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @g() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  store i8 65, i8* %1, align 1
  store i16 2, i16* %2, align 2
  store i32 1, i32* %3, align 4
  store double 1.200000e+00, double* %4, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @h() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  %5 = alloca double, align 8
  %6 = load i8, i8* @global_char, align 1
  store i8 %6, i8* %1, align 1
  %7 = load i16, i16* @global_short, align 2
  store i16 %7, i16* %2, align 2
  %8 = load i32, i32* @global_int, align 4
  store i32 %8, i32* %3, align 4
  %9 = load double, double* @global_double, align 8
  store double %9, double* %4, align 8
  %10 = load double, double* @global_double, align 8
  store double %10, double* %5, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @i() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  %5 = alloca i8, align 1
  %6 = alloca i16, align 2
  %7 = alloca i32, align 4
  %8 = alloca double, align 8
  %9 = load i8, i8* %1, align 1
  store i8 %9, i8* %5, align 1
  %10 = load i16, i16* %2, align 2
  store i16 %10, i16* %6, align 2
  %11 = load i32, i32* %3, align 4
  store i32 %11, i32* %7, align 4
  %12 = load double, double* %4, align 8
  store double %12, double* %8, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @j() #0 {
  store i8 66, i8* @global_char, align 1
  store i32 10, i32* @global_int, align 4
  store i16 12, i16* @global_short, align 2
  store double 1.300000e+00, double* @global_double, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @l() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  %5 = load i8, i8* %1, align 1
  store i8 %5, i8* @global_char, align 1
  %6 = load i16, i16* %2, align 2
  %7 = sext i16 %6 to i32
  store i32 %7, i32* @global_int, align 4
  %8 = load i32, i32* %3, align 4
  %9 = trunc i32 %8 to i16
  store i16 %9, i16* @global_short, align 2
  %10 = load double, double* %4, align 8
  store double %10, double* @global_double, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @m() #0 {
  %1 = load i8, i8* @global_a, align 1
  store i8 %1, i8* @global_char, align 1
  %2 = load i16, i16* @global_b, align 2
  %3 = sext i16 %2 to i32
  store i32 %3, i32* @global_int, align 4
  %4 = load i32, i32* @global_c, align 4
  %5 = trunc i32 %4 to i16
  store i16 %5, i16* @global_short, align 2
  %6 = load double, double* @global_d, align 8
  store double %6, double* @global_double, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @downcast_store() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  %5 = load i8, i8* %1, align 1
  %6 = sitofp i8 %5 to double
  store double %6, double* %4, align 8
  %7 = load i16, i16* %2, align 2
  %8 = sitofp i16 %7 to double
  store double %8, double* %4, align 8
  %9 = load i32, i32* %3, align 4
  %10 = sitofp i32 %9 to double
  store double %10, double* %4, align 8
  %11 = load i8, i8* @global_a, align 1
  %12 = sitofp i8 %11 to double
  store double %12, double* @global_double, align 8
  %13 = load i16, i16* @global_b, align 2
  %14 = sitofp i16 %13 to double
  store double %14, double* @global_double, align 8
  %15 = load i32, i32* @global_c, align 4
  %16 = sitofp i32 %15 to double
  store double %16, double* @global_double, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define void @downcast_declaration() #0 {
  %1 = alloca i8, align 1
  %2 = alloca i16, align 2
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  %5 = alloca double, align 8
  %6 = alloca double, align 8
  %7 = alloca double, align 8
  %8 = alloca double, align 8
  %9 = load i8, i8* %1, align 1
  %10 = sitofp i8 %9 to double
  store double %10, double* %5, align 8
  %11 = load i16, i16* %2, align 2
  %12 = sitofp i16 %11 to double
  store double %12, double* %6, align 8
  %13 = load i32, i32* %3, align 4
  %14 = sitofp i32 %13 to double
  store double %14, double* %7, align 8
  %15 = load double, double* %4, align 8
  store double %15, double* %8, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  ret i32 0
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1-19ubuntu1 (tags/RELEASE_391/rc2)"}
