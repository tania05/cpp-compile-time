//Author: Tania Akter, V00810640

#include "ra/cexpr_basic_string.hpp"

int main()
{
    using namespace ra::expr;
    using namespace std;

    //creating empty string
    cexpr_basic_string<char, 3> x();

    // null terminated character array as input constructor
    const char my_array[10] = "work";
    cexpr_basic_string<char, 3> y(my_array);
}