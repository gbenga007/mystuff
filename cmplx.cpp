#include "cmplx.h"

namespace ece3220{
//Example: cout << a; // a is RHS
//Printss a complex object as '(r,i)'
/*friend*/
std::ostream &
    
    operator << (std::ostream &os, const ece3220::cmplx &rhs)
    {

        os << '(' << rhs.real << ',' << rhs.imag << ')';
        return os;

    }   

/*friend*/
std::istream &
    operator >> (std::istream &is, cmplx &rhs)
    {   
        char c; 
        double real_tmp = 0.0 , imag_tmp = 0.0;
        // attempt to read the parantheses       
        is >> std::skipws >> c;
         
         if(!is) return is;
        // if we read successfully but c is not a parantheses then we want to set the fail bit
       if( is && (c!='(')){
        is.setstate(std::ios::failbit);
        return is;
        }
         
         // attempt to read the real part
         is >> real_tmp;
        
        if( !is){
            //is.setstate(std::ios::failbit);
            return is;
        }
        
        // attempt to read ','
        if(!is) return is;
        if(c!=','){

            is.setstate(std::ios::failbit);
            return is;
        }

        is >> imag_tmp;
        if(!is) {

            return is;
        }
        


        // Attempt to read is
        if(!is) return is;
        if((c!=')')){
            //A char was read and it wasnt ')'
            is.setstate(std::ios::failbit);
            return is;
        }

         rhs.real = real_tmp;
         rhs.imag = imag_tmp;

        return is;
}

} // namespace ece3220 ends..

