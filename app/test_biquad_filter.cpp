//Author: Tania Akter, V00810640

#include "ra/biquad_filter.hpp"
#include <iostream>

int main() 
{
    using namespace ra::biquad;
    using namespace std;

    constexpr double f = 0.98;
    constexpr double q = 0.7071;
    constexpr auto filter = lowpass<double>(f,q);
    cout << "Lowpass" << endl;
    cout << "a0 " << filter.a0 << endl;
    cout << "a1 " << filter.a1 << endl;
    cout << "a2 " << filter.a2 << endl;
    cout << "b0 " << filter.b0 << endl;
    cout << "b1 " << filter.b1 << endl;
    cout << "b2 " << filter.b2 << endl << endl;

    constexpr auto h_filter = highpass<double>(f,q);
    cout << "Highpass" << endl;
    cout << "a0 " << h_filter.a0 << endl;
    cout << "a1 " << h_filter.a1 << endl;
    cout << "a2 " << h_filter.a2 << endl;
    cout << "b0 " << h_filter.b0 << endl;
    cout << "b1 " << h_filter.b1 << endl;
    cout << "b2 " << h_filter.b2 << endl << endl;

    constexpr auto bp_filter = bandpass<double>(f,q);
    cout << "Bandpass" << endl;
    cout << "a0 " << bp_filter.a0 << endl;
    cout << "a1 " << bp_filter.a1 << endl;
    cout << "a2 " << bp_filter.a2 << endl;
    cout << "b0 " << bp_filter.b0 << endl;
    cout << "b1 " << bp_filter.b1 << endl;
    cout << "b2 " << bp_filter.b2 << endl << endl;

    constexpr auto lsb_filter = lowshelf_boost<double>(f,double(1.5));
    cout << "low-frequency shelving boost" << endl;
    cout << "a0 " << lsb_filter.a0 << endl;
    cout << "a1 " << lsb_filter.a1 << endl;
    cout << "a2 " << lsb_filter.a2 << endl;
    cout << "b0 " << lsb_filter.b0 << endl;
    cout << "b1 " << lsb_filter.b1 << endl;
    cout << "b2 " << lsb_filter.b2 << endl << endl;

    constexpr auto lsc_filter = lowshelf_cut<double>(f,double(1.5));
    cout << "low-frequency shelving cut" << endl;
    cout << "a0 " << lsc_filter.a0 << endl;
    cout << "a1 " << lsc_filter.a1 << endl;
    cout << "a2 " << lsc_filter.a2 << endl;
    cout << "b0 " << lsc_filter.b0 << endl;
    cout << "b1 " << lsc_filter.b1 << endl;
    cout << "b2 " << lsc_filter.b2 << endl << endl;
    
}