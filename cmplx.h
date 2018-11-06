#ifndef ECE3220_CMPLX_H
#define ECE3220_CMPLX_H


#include <iostream>

namespace ece3220{ // so that what we create does not conflict with similar things in perhaps the std library or someone elses work
    
    class cmplx {
        public:
            inline cmplx() throw()
            : real(0),imag(0)
            {} 
            
            inline cmplx(const double r, const double im) throw()
            : real(r), imag(im)
            {}
        
            ~cmplx() = default;
        protected:
            double real,imag; // real and imaginary
        /*friends*/
        friend std::ostream &
        operator << (std::ostream &os, const cmplx &rhs);

        friend std::istream &
        operator >> (std::istream &is, cmplx &rhs);
    
    
    };

        /*friends*/
        std::ostream &
        operator << (std::ostream &os, const cmplx &rhs);

        std::istream &
        operator >> (std::istream &is, cmplx &rhs);
    

}


#endif
