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
    Fraction(int Numerator, int Denominator);
    Fraction(int Whole, int Numerator, int Denominator);
    
    friend std::ostream& operator<<(std::ostream& out, const Fraction& self){
        out << self.num << "/" << self.den << std::endl;
        return out;
    }   
    
    Fraction reduce(const Fraction&);

    /**
     * Math Operators:
     *     START
     */
    int operator/(const Fraction& self);
    int operator*(const Fraction& self);
    int operator+(const Fraction& self);
    int operator-(const Fraction& self);

    /**
     * Boolean Operators:
     *      START
     */
    bool operator==(const Fraction& self){
        return num == self.num && den == self.den;
    }
    
    bool operator>(const Fraction& self){
        if(den == self.den){
            return num > self.num;
        }
        return den > self.den;
    }

    bool operator>(const Fraction& self){
        if(den == self.den){
            return num < self.num;
        }
        return den < self.den;
    }
protected:
    int num, den, fac;
};

#endif