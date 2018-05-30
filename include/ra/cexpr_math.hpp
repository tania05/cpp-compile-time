#Author: Tania Akter, V
#ifndef CEXPR_MATH_H
#define CEXPR_MATH_H

 namespace ra :: cexpr_math {

         // The math constant pi.
         // The type T is a floating-point type.
         template <class T >
         constexpr T pi = boost :: math :: constants :: pi <T >();

         // Returns the absolute value of x.
         // The type T is a floating-point type.
         template <class T >
         constexpr T abs (T x );

         // Returns the square of x.
         // The type T is a floating-point type.
         template <class T >
         constexpr T sqr (T x );

         // Returns the cube of x.
         // The type T is a floating-point type.
         template <class T >
         constexpr T cube (T x );

         // Returns the remainder after division when x is divided by y.
         // In particular, x - n y is returned where n is the result obtained by
         // dividing x by y and then rounding (to an integer value) toward zero.
         // If y is zero, an exception of type std::overflow_error is thrown.
         // The type T is a floating-point type.
         template <class T >
         constexpr T mod (T x , T y );

         // Returns the sine of x.
         // Note that a particular algorithm must be used to implement this
         // function.
         // The type T is a floating-point type.
         template <class T >
         constexpr T sin (T x );

         // Returns the cosine of x.
         // Note that a particular algorithm must be used to implement this
         // function.
         // The type T is a floating-point type.
         template <class T >
         constexpr T cos (T x );

         // Returns the tangent of x.
         // Note that a particular algorithm must be used to implement this
         // function.
         // If the tangent of x is infinite, an exception of type
         // std::overflow_error is thrown.
         // The type T is a floating-point type.
         template <class T >
         constexpr T tan (T x );

         // Returns the square root of x.
         // If x is negative, an exception of type std::domain_error is thrown.
         // Note that a particular algorithm must be used to implement this
         // function.
         // The type T is a floating-point type.
         template <class T >
         constexpr T sqrt (T x );
}
#endif
