//Author: Tania Akter, V00810640

#include "ra/cexpr_math.hpp"

#include <cassert>
#include <boost/math/constants/constants.hpp>

// #include <stdio>

int main() 
{
    using namespace ra::cexpr_math;
    using namespace std;

    assert(abs<float>(1.24) == (float)1.24);

    assert(abs<float>(-1.23) == (float)1.23);
    float p = boost::math::constants::pi<float>();
    // cout << p << endl;
    float s = sin<float>(p);
    cout << s << endl;
    // assert(s == 0);
    cout << sqrt<float>(4) << endl;
    cout << cos<float>(-p/2) << endl;
    cout << cos<float>(-p/2) << endl;
    cout << tan<float>(p/4) << endl;
    return 0;   
}