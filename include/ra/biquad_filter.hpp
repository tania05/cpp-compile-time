#Author: Tania Akter, V

#ifndef BIQUAD_FILTER_H
#define BIQUAD_FILTER_H
namespace ra :: biquad {
    // Biquad filter coefficients class.
    template <class Real >
    struct biquad_filter_coefs
    {
        // The real number type used to represent the filter coefficients.
        using real = Real ;

        // Creates a set of filter coefficients where the coefficients
        // a0, a1, a2, b0, b1, and b2 are initialized to a0_, a1_, a2_,
        // b0_, b1_, and b2_, respectively.
        constexpr biquad_filter_coefs ( real a0_ , real a1_ , real a2_ , real b0_ ,
                               real b1_ , real b2_ );

        // Creates a set of filter coefficients by copying from another set.
        // Since Real and OtherReal need not be the same, this constructor
        // can be used to convert between filter coefficients of different
        // types.
        template <class OtherReal >
        constexpr biquad_filter_coefs (
                const biquad_filter_coefs < OtherReal >& coefs );
        // The filter coefficients a0, a1, a2, b0, b1, and b2.
        real a0 ;
        real a1 ;
        real a2 ;
        real b0 ;
        real b1 ;
        real b2 ;
    };

    // Returns the coefficients for a biquad lowpass filter with normalized
        // cutoff frequency f and Q factor q, where f in [0,1] and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real >
    constexpr biquad_filter_coefs < Real > lowpass ( Real f , Real q );

    // Returns the coefficients for a biquad highpass filter with
    // normalized cutoff frequency f and Q factor q, where f in [0,1]
    // and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real >
    constexpr biquad_filter_coefs < Real > highpass ( Real f , Real q );

    // Returns the coefficients for a biquad bandpass filter with
    // normalized cutoff frequency f and Q factor q, where f in [0,1]
    // and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real >
    constexpr biquad_filter_coefs < Real > bandpass ( Real f , Real q );

    // Returns the coefficients for a biquad low-frequency shelving
    // boost filter with normalized cutoff frequency f and gain-control
    // parameter a, where f in [0,1] and a >= 0.
    // For a gain in dB of G (where G > 0), choose a =10 ˆ (G / 20).
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real >
    constexpr biquad_filter_coefs < Real > lowshelf_boost ( Real f , Real a );

    // Returns the coefficients for a biquad low-frequency shelving
    // cut filter with normalized cutoff frequency f and gain-control
    // parameter a, where f in [0,1] and a >= 0.
    // For a gain in dB of G (where G < 0), choose a = 10 ˆ (-G / 20).
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real >
    constexpr biquad_filter_coefs < Real > lowshelf_cut ( Real f , Real a );
}
#endif
