//Author: Tania Akter, V00810640
#ifndef mandelbrot_hpp
#define mandelbrot_hpp

#include <utility>
#include "ra/cexpr_basic_string.hpp"

namespace ra{
namespace fractal {

    constexpr bool is_member(std::pair<double, double> complex)
    {
        std::pair<double, double> c = complex;
        double before_re = complex.first;
        double before_img = complex.second;
        std::pair<double, double> before = complex;
        for(int i = 1; i<16; i++)
        {
            
            if( before_re * before_re + before_img * before_img > 4)
            {
                return false;
            }
            double re = ((before_re * before_re) - before_img*before_img) + c.first;
            double img = 2*before_re*before_img + c.second;

            before_re = re;
            before_img = img;            
        }
        return true;
    }


    constexpr std::pair<double, double> lambda(std::size_t W , std::size_t H, double k, double l)
    {
        double a0 = -1.6;
        double a1 = -1.1;
        double b0 = 0.6;
        double b1 = 1.1;

        double real_n = b0 - a0;
        double real_d = W-1;

        double img_n = b1 - a1;
        double img_d = H -1;

        double real = a0 + k*(real_n/real_d);
        double img = a1 + (H-1-l)*(img_n/img_d);
        return std::make_pair(real,img);
    }  
    
    template <std :: size_t W , std :: size_t H >    
    constexpr ra::cexpr::cexpr_string<(W+1)*(H+2)+1> mandelbrot_begin()
    {
        ra::cexpr::cexpr_string<(W+1)*(H+2)+1> str;
        str.push_back('P');
        str.push_back('1');
        str.append(" ");
        char w_buff[64] = {0};
        char h_buff[64] = {0};
        ra::cexpr::to_string(W, w_buff, 64, nullptr);
        ra::cexpr::to_string(H, h_buff, 64, nullptr);
        str.append(w_buff);
        str.append(" ");
        str.append(h_buff);
        str.push_back('\n');
        

        for(std::size_t i = 0; i< H; ++i)
        {
            for(std::size_t j = 0 ; j < W; ++j)
            {
                auto c = lambda(W,H,j,i);
                if(is_member(c))
                {
                    str.push_back('1');
                }
                else
                {
                    str.push_back('0');
                }
            }
            str.push_back('\n');
        }
        return str;
    }



    // A variable template for a string that represents an image depicting
    // the Mandelbrot set. The image has width W and height H.
    // This object must be of type cexpr_string<M> for some appropriate M.
    // The string is a binary image encoded in the text-based bitmap PNM
    // format.
    template <std :: size_t W , std :: size_t H >
    constexpr auto mandelbrot = mandelbrot_begin<W,H>();
}
}

#endif
