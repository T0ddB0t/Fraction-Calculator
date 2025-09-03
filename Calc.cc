#include "Calc.h"


//Functions 
Fraction Fraction::maximize() const {
    int newFac = fac * den;
    int newNum = num + newFac;

    return Fraction(0, newNum, den);
}

/**
 * With the + and - operators, I have to fix the simplification process.
 * EDIT: with the + and - operators, it works now, but I don't like how
 *       the algorithm for it.
 * TODO: Fix the simplification
 * 
 * The state I have it at right now is unapologetic,
 * will take a crack at thinking of more ways to improve
 */

Fraction Fraction::simplify(int num, int den) const {
    bool isNeg = false;
    if(num < 0){
        num = fabs(num);
        isNeg = true;
    }

    int remainder = num % den;
    if(remainder > 0 && remainder != num){
        num /= remainder;
        den /= remainder;
    } 

    if(isNeg){
        num *= -1;
    }

    return Fraction(num, den);
}

Fraction Fraction::reduce() const {
    int newNum = num;
    int newFac = fac;

    while(newNum > den){
        newNum - den;
        newFac++;
    }

    return Fraction(newFac, newNum, den);
}

//Math Operators

Fraction Fraction::operator/(const Fraction& other){
    int n = num * other.den;
    int d = den * other.num;

    //simplify
    Fraction output = simplify(n, d);

    return output; 
}

Fraction Fraction::operator*(const Fraction& other){
    int n = num * other.num;
    int d = den * other.den;

    Fraction output = simplify(n, d);

    return output; 
}

Fraction Fraction::operator+(const Fraction& other){
    int n = (num * other.den) + (other.num * den);
    int d = den * other.den;

    Fraction output = simplify(n, d);

    return output; 
}

Fraction Fraction::operator-(const Fraction& other){
    int n = (num * other.den) - (other.num * den);
    int d = den * other.den;

    Fraction output = simplify(n, d);

    return output; 
}

//Boolean Operators

bool Fraction::operator==(const Fraction& self){
    return num == self.num && den == self.den;
}

bool Fraction::operator>(const Fraction& self){
    if(den == self.den){
        return num > self.num;
    }
    return den > self.den;
}

bool Fraction::operator<(const Fraction& self){
    if(den == self.den){
        return num < self.num;
    }
    return den < self.den;
}

bool Fraction::operator<=(const Fraction& self){
    if(den == self.den){
        return num <= self.num;
    }
    return den <= self.den;
}

bool Fraction::operator>=(const Fraction& self){
    if(den == self.den){
        return num >= self.num;
    }
    return den >= self.den;
}
