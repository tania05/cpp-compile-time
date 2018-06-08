//Author: Tania Akter, V00810640
#include <iostream>
#include "ra/mandelbrot.hpp"
#include <fstream>

int main ()
{
    using namespace std;
   // Force the image (in PNM format) to be computed at compile time.
       constexpr auto s = ra::fractal::mandelbrot <256, 256>;

       // Output the image (in PNM format).
       auto content = s.begin();
       std :: cout << s.begin () << '\n';
        ofstream file;
        file.open("mandelbrot.pnm");
        file << content;
        file.close();
}
