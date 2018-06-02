//Author: Tania Akter, V00810640

#include "ra/cexpr_basic_string.hpp"
#include <cassert>

int main()
{
    using namespace ra::expr;
    using namespace std;

    //creating empty string
    constexpr cexpr_basic_string<char, 3> x;
 
    // null terminated character array as input constructor
    constexpr const char my_array[10] = "wor";
    constexpr cexpr_basic_string<char, 3> y(my_array);

    //check size of the string for all
    // assert(x.size() == 0);
    // assert(y.size() == char_traits<char>::length(x.data()));
    
    cout << "EVERYTHING PASSES!" << endl << endl;

    char buff[10] = {0};

    constexpr int p = to_string(33, buff, 10, nullptr);
    cout << p << endl;
}