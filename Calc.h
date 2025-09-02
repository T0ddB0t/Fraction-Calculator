#ifndef CALC_H
#define CALC_H

/**
 * Author: Francisco Sanchez
 * Made: September, 2nd 2025
 */

#include <iostream>

class Fraction{
public:
    /**
     * Fraction constructor:
     *     One constructor will be the regular N/D,
     *     and the other will convert to N/D
     */
    Fraction(int , int);
    Fraction(int , int , int);
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& self){
        out << self.num << "/" << self.den << std::endl;
        return out;
    }   
    /**
     * reduce Function:
     *     Will be used to convert the factor of
     *     the fraction to be part of the numerator  
     */
    Fraction reduce() const;

    /**
     * Math Operators:
     *     Overloaded: Divide
     *                 Multiply
     *                 Add
     *                 Subtract
     */
    int operator/(const Fraction& );
    int operator*(const Fraction& );
    int operator+(const Fraction& );
    int operator-(const Fraction& );

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
};

#endif