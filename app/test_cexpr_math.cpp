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

    constexpr auto epsln = std::numeric_limits<float>::epsilon();

    static_assert(abs<float>(1.24) == std::abs((float)1.24), "Absolute vlaue of normal float is not properly given");
    
    static_assert(abs<float>(-1.23) == std::abs((float)-1.23),"Absolute value of negative float is not properly implemented");
    
    float p = boost::math::constants::pi<float>();
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
    static_assert(std::abs(std::abs(sin<float>(5))- (float)0.95892427466) <= epsln , "Error in sin");
    // static_assert(std::abs(std::abs(sin<float>(-5)) - (float)0.95892427466) <= epsln , "Error in sin");
    // std::cout << sin<float>(-5) << std::endl;
    static_assert(std::abs(std::abs(sin<float>(0))- (float)0) <= epsln , "sin 0 should be 0");
    static_assert(std::abs(std::abs(sin<float>(pi<float>/2))- (float)1) <= epsln , "sin pi/2 should be 1");

    //sqrt
    std::cout << sqrt<float>(0.65793) << std::endl;
    std::cout << std::sqrt((float)0.65793) << std::endl;
    std::cout << sqrt<float>(0.65793) - std::sqrt((float)0.65793) << std::endl;
    static_assert(sqrt<float>(0.65793) - (float)0.811129 <= epsln, "square root fails");
    static_assert(sqrt<float>(0) == (float)0, "square root of 0 fails");
    
    return 0;   
    
}