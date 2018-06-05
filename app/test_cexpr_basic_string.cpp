//Author: Tania Akter, V00810640

#include "ra/cexpr_basic_string.hpp"
#include <cassert>
#include <typeinfo>
#include <string.h>

int main()
{
    using namespace ra::cexpr;
    using namespace std;
 
    //creating empty string
    constexpr cexpr_basic_string<char, 3> x;
 
    // null terminated character array as input constructor
    constexpr char my_array[10] = "wor";
    
    constexpr cexpr_basic_string<char, 3> y(my_array);

    //check size of the string for all
    assert(x.size() == char_traits<char>::length(x.data()));
    assert(y.size() == char_traits<char>::length(y.data()));
    
    //check begin and end   

    //creating a string with the content specified by first and last
    cexpr_basic_string<char, 3>::const_iterator first = y.begin();
    cexpr_basic_string<char, 3>::const_iterator last = y.end();
    cexpr_basic_string<char, 3> se(first, last);
    assert(se.size() == char_traits<char>::length(se.data()));
    assert(se.size() == y.size());
    
    const char * se_data1 = se.data();
    const char * se_data2 = y.data();
    
    assert(strcmp(se_data1, se_data2) == 0);

    //should fail
    //cexpr_basic_string<char, 2> se2(first, last);
    //check for references
    cexpr_basic_string<char, 3>::const_reference cr1 =  y[1];
    assert(cr1 == y.data()[1]);

    cexpr_basic_string<char, 3>::reference cr2 = se[0];
    assert(cr2 == se.data()[0]);


    // pushback

    cexpr_basic_string<char, 3> pb;
    pb.push_back('a');
    assert(strcmp(pb.data(), "a") == 0);
    pb.push_back('c');
    assert(strcmp(pb.data(), "ac") == 0);
    pb.push_back('t');
    assert(strcmp(pb.data(), "act") == 0);
    //should fail
    // pb.push_back('a');

    //pop_back
    pb.pop_back();
    assert(strcmp(pb.data(), "ac") == 0);
    pb.pop_back();
    assert(strcmp(pb.data(), "a") == 0);
    pb.pop_back();
    assert(strcmp(pb.data(), "") == 0);
    //should fail
    // pb.pop_back();

    //append
    pb.append("aa");
    assert(strcmp(pb.data(), "aa") == 0);
    pb.append("a");
    assert(strcmp(pb.data(), "aaa") == 0);
    //should fail
    // pb.append("a");
    
    pb.pop_back();
    pb.pop_back();
    pb.pop_back();

    cexpr_basic_string<char, 4> other("thr");
    pb.append(other);
    assert(strcmp(pb.data(), other.data()) == 0);

    //should fail
    // cexpr_basic_string<char, 6> other2("Fail");
    // other.append(other2);  
    
    // cout << "EVERYTHING PASSES!" << endl << endl;
    // char buff[10] = {0};
    // constexpr size_t p = to_string(33, buff, 10, nullptr);
    // cout << p << endl;



}