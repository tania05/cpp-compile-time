//Author: Tania Akter, V00810640

#include "ra/cexpr_math.hpp"

#include <cassert>
#include <boost/math/constants/constants.hpp>
#include <assert.h>
#include <cmath>
// #include <stdio>

int main() 
{
    using namespace ra::cexpr_math;
    // using namespace std;

    // std::cout.precision(std::numeric_limits<float>::max_digits10);
    
    constexpr auto epsln = std::numeric_limits<float>::epsilon();

    static_assert(abs<float>(1.24) == std::abs((float)1.24), "Absolute vlaue of normal float is not properly given");
    
    static_assert(abs<float>(-1.23) == std::abs((float)-1.23),"Absolute value of negative float is not properly implemented");
    
    constexpr float p = boost::math::constants::pi<float>();
    // cout << p << endl;
    // float s = sin<float>(p);
    // cout << s << endl;
    // assert(s == 0);
    // std::cout << sqrt<float>(4) << std::endl;
    // std::cout << cos<float>(-p/2) << std::endl;
    // std::cout << cos<float>(-p/2) << std::endl;
    // std::cout << tan<float>(p/4) << std::endl;

    //check for sqr
    static_assert(sqr<float>(8.95) == (float)8.95 * (float)8.95, "Square root of positive number don't match");
    static_assert(sqr<float>(-8.95) == (float)-8.95 * (float)-8.95, "Square root of positive number don't match");
    static_assert(sqr<float>(0) == 0, "Square of 0 is not 0");
    static_assert(sqr<float>(-0) == 0, "Square of -0 is not 0");

    //check for cube
    static_assert(cube<float>(-0) == 0, "Cube of -0 should be 0");
    static_assert(cube<float>(0) == 0, "Cube of -0 should be 0");
    static_assert(cube<float>(4.609) == (float)4.609 * (float)4.609 * (float)4.609 , "Cube of +ve failed");
    static_assert(cube<float>(-4.609) == (float)-4.609 * (float)-4.609 * (float)-4.609 , "Cube of -ve failed");
    static_assert(cube<float>(-4.609) < 0 , "Cube of -ve should be -ve"); 

    //sin
    static_assert(std::abs(sin<float>(5)- (float)-0.95892427466) <= epsln , "Error in sin5");
    static_assert(std::abs(sin<float>(-5)- (float)0.95892427466) <= epsln , "Error in sin-5"); 
    static_assert(std::abs(sin<float>(7)- (float)0.65698659871) <= epsln , "Error in sin7");
    static_assert(std::abs(sin<float>(-7)- (float)-0.65698659871) <= epsln , "Error in sin-7");
    
    std::cout << sin<float>(p) << std::endl;
    std::cout << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << sin<float>(p)- (float)0 << std::endl;


    static_assert(std::abs(std::abs(sin<float>(p))- (float)0) <= epsln*10 , "Error in sin pi");
    static_assert(std::abs(std::abs(sin<float>(-p))- (float)0) <= epsln*10 , "Error in sin -pi");
    static_assert(std::abs(sin<float>(p/2)- (float)1) <= epsln , "Error in sin pi/2");
    static_assert(std::abs(sin<float>(-p/2)- (float)-1) <= epsln , "Error in -pi/2");
    static_assert(std::abs(sin<float>(2*p)- (float)0) <= epsln , "Error in 2*pi");
    static_assert(std::abs(sin<float>(-2*p)- (float)0) <= epsln , "Error in -2*pi");
    static_assert(std::abs(sin<float>(0)- (float)0) <= epsln , "Error in 0");
    static_assert(std::abs(sin<float>(-0)- (float)0) <= epsln , "Error in -0");
  

    //cos
    static_assert(std::abs(cos<float>(5)- (float)0.28366218546) <= epsln*10 , "Error in cos");
    static_assert(std::abs(cos<float>(-5)- (float)0.28366218546) <= epsln*10 , "Error in cos-5"); 
    static_assert(std::abs(cos<float>(7)- (float)0.75390225434) <= epsln*10 , "Error in cos7");
    static_assert(std::abs(cos<float>(-7)- (float)0.75390225434) <= epsln*10 , "Error in cos-7");
    // std::cout << cos<float>(p) << std::endl;

    // // std::cout << epsln << std::endl;
    // // std::cout << cos<float>(p)- (float)1 << std::endl;
    // // std::cout << sin<float>(p)- (float)0 << std::endl;
    static_assert(std::abs(cos<float>(-p)- (float)-1) <= epsln , "Error in cos -pi");
    static_assert(std::abs(cos<float>(p/2)- (float)0) <= epsln*10 , "Error in cos pi/2");
    static_assert(std::abs(cos<float>(p)- (float)-1) <= epsln , "Error in cos pi");
    static_assert(std::abs(cos<float>(-p/2)- (float)0) <= epsln*10 , "Error in cos -pi/2");
    static_assert(std::abs(cos<float>(2*p)- (float)1) <= epsln , "Error in cos 2*pi");
    static_assert(std::abs(cos<float>(-2*p)- (float)1) <= epsln , "Error in cos -2*pi");
    static_assert(std::abs(cos<float>(0)- (float)1) <= epsln , "Error in cos 0");
    static_assert(std::abs(cos<float>(-0)- (float)1) <= epsln , "Error in cos 0");

    //tan
    static_assert(std::abs(tan<float>(5)- (float)-3.38051500625) <= epsln*1000 , "Error in tan5");
    static_assert(std::abs(tan<float>(-5)- (float)3.38051500625) <= epsln*1000 , "Error in tan-5"); 
    static_assert(std::abs(tan<float>(7)- (float)0.87144798272) <= epsln*1000 , "Error in tan7");
    static_assert(std::abs(tan<float>(-7)- (float)-0.87144798272) <= epsln*1000 , "Error in tan-7");
    std::cout << tan<float>(5) << std::endl;

    // std::cout << epsln << std::endl;
    // std::cout << tan<float>(5)- (float)-3.38051500625 << std::endl;
    // std::cout << sin<float>(p)- (float)0 << std::endl;
    static_assert(std::abs(tan<float>(p/4)- (float)1) <= epsln*10 , "Error in tan pi");
    static_assert(std::abs(tan<float>(-p/4)- (float)-1) <= epsln*10 , "Error in tan pi");
    static_assert(std::abs(tan<float>(p)- (float)0) <= epsln*10 , "Error in tan pi");
    static_assert(std::abs(tan<float>(-p)- (float)0) <= epsln*10 , "Error in tan -pi");
    // static_assert(std::abs(tan<float>(p/2)- (float)0) <= epsln*10 , "Error in tan pi/2");
    // static_assert(std::abs(tan<float>(-p/2)- (float)0) <= epsln*10 , "Error in tan -pi/2");
    static_assert(std::abs(tan<float>(2*p)- (float)0) <= epsln , "Error in tan 2*pi");
    static_assert(std::abs(tan<float>(-2*p)- (float)0) <= epsln , "Error in tan-2*pi");
    static_assert(std::abs(tan<float>(0)- (float)0) <= epsln , "Error in tan 0");
    static_assert(std::abs(tan<float>(-0)- (float)0) <= epsln , "Error in tan 0");

    //sqrt
    // std::cout << sqrt<float>(0.65793) << std::endl;
    // std::cout << std::sqrt((float)0.65793) << std::endl;
    // std::cout << sqrt<float>(0.65793) - std::sqrt((float)0.65793) << std::endl;
    static_assert(sqrt<float>(0.65793) - (float)0.811129 <= epsln, "square root fails");
    static_assert(sqrt<float>(0) == (float)0, "square root of 0 fails");
// std::cout<<"latest"<<std::endl;

    //check mod
    static_assert(mod<float>(-3.0, -2.0) == (float)-1, "mod of negative numbers");
    // std::cout << mod<float>(-3.0,2.0) << std::endl;
    // std::cout << mod<float>(3.0,-2.0) << std::endl;
    static_assert(mod<float>(-3.0, 2.0) == (float)-1, "mod of negative numerator");
    static_assert(mod<float>(3.0, -2.0) == (float)1, "mod of negative denominator");
    // mod<float>(3,0);
    
    return 0;   
}