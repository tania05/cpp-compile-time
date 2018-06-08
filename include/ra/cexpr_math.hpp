//Author: Tania Akter, V00810640
#ifndef cexpr_math_hpp
#define cexpr_math_hpp

#include <boost/math/constants/constants.hpp>

namespace ra {
namespace cexpr_math {

  // The math constant pi.
  // The type T is a floating-point type.
  template <class T >
  constexpr T pi = boost::math::constants::pi<T>();

  // Returns the absolute value of x.
  // The type T is a floating-point type.
  template <class T >
  constexpr T abs (T x )
  {
    return (x < 0) ? -x : x;
  }

  // Returns the square of x.
  // The type T is a floating-point type.
  template <class T >
  constexpr T sqr (T x )
  {
    return x*x;
  }

  // Returns the cube of x.
  // The type T is a floating-point type.
  template <class T >
  constexpr T cube (T x )
  {
    return x*x*x;
  }

  // Returns the remainder after division when x is divided by y.
  // In particular, x - n y is returned where n is the result obtained by
  // dividing x by y and then rounding (to an integer value) toward zero.
  // If y is zero, an exception of type std::overflow_error is thrown.
  // The type T is a floating-point type.
  template <class T >
  constexpr T mod (T x , T y )
  {
    if(y == T(0))
    {
      throw std::overflow_error("Value of y is 0");
    }
    // std::cout << x - ((int)(x/y)) * y << std::endl;
    // throw std::runtime_error("tandom");
    return x - ((long long)(x/y)) * y;
  }

  // Returns the sine of x.
  // Note that a particular algorithm must be used to implement this
  // function.
  // The type T is a floating-point type.
  template <class T >
  constexpr T sin (T x )
  {      
    if(abs<T>(x) <= 0.000001)
    {
      return x;
    }

    x = mod<T>(x, 2*pi<T>);          
    T sx3 = sin(x/3);
    return ( 3*(sx3)  - 4*cube(sx3) );    
  }

  // Returns the cosine of x.
  // Note that a particular algorithm must be used to implement this
  // function.
  // The type T is a floating-point type.
  template <class T >
  constexpr T cos (T x )
  {
    x = (pi<T>/2) - x;
    return sin(x); 
  }

  // Returns the tangent of x.
  // Note that a particular algorithm must be used to implement this
  // function.
  // If the tangent of x is infinite, an exception of type
  // std::overflow_error is thrown.
  // The type T is a floating-point type.
  template <class T >
  constexpr T tan (T x )
  {
    if(cos<T>(x) == 0)
    {
      throw std::overflow_error("cos x is 0");
    }  
    //TODO test 
    return sin(x)/cos(x);   
  }

  // Returns the square root of x.
  // If x is negative, an exception of type std::domain_error is thrown.
  // Note that a particular algorithm must be used to implement this
  // function.
  // The type T is a floating-point type.
  template <class T >
  constexpr T sqrt (T x )
  {
    if(x<0)
    {
      throw std::domain_error("X is negative.");
    }
    if(x == 0)
    {
     return 0; 
    }
    T x0 = x;
    T next = x0 - (sqr(x) - x0) / (2*x);
    while(abs<T>(next - x) > std::numeric_limits<T>::epsilon())
    {
      x = next;
      next = x - (sqr(x) - x0) / (2*x);
    }
    return next;
  }
}
}

#endif
