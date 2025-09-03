#ifndef CALC_H
#define CALC_H

/**
 * Author: Francisco Sanchez
 * Made: September, 2nd 2025
 */

#include <iostream>
#include <math.h>
class Fraction{
public:
    /**
     * Fraction constructor:
     *     One constructor will be the regular N/D,
     *     and the other will be F N/D
     */
    Fraction(int Numerator, int Denominator) : num(Numerator), den(Denominator) {}

    Fraction(int Factor, int Numerator, int Denominator) : fac(Factor), num(Numerator), den(Denominator) {}
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& self){
        out << self.fac << " " << self.num << "/" << self.den << std::endl;
        return out;
    }   
    /**
     * Functions:
     *      maximize:
     *          Will be used to convert the factor of
     *          the fraction to be part of the numerator
     *      reduce:
     *          Will be used to reduce the fraction to
     *          have a whole number if possible  
     */
    
    Fraction maximize() const;
    Fraction reduce() const;

    /**
     * Math Operators:
     *     Overloaded: Divide
     *                 Multiply
     *                 Add
     *                 Subtract
     */
    Fraction operator/(const Fraction& );
    Fraction operator*(const Fraction& );
    Fraction operator+(const Fraction& );
    Fraction operator-(const Fraction& );

    /**
     * Boolean Operators:
     *      Overloaded: Equal to
     *                  Less than
     *                  Greater than
     *                  Less than or equal to
     *                  Greater than equal to
     */
    bool operator==(const Fraction& );
    bool operator>(const Fraction& );
    bool operator<(const Fraction& );
    bool operator>=(const Fraction& );
    bool operator<=(const Fraction& );
private:
    int num, den, fac = 0;
    Fraction simplify(int , int ) const ;
};

#endif