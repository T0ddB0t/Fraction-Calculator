#include "Calc.h"

Fraction Fraction::reduce() const {
    int newNum = num;
    int newFac = fac;

    while(newNum > den){
        newNum - den;
        newFac++;
    }
    
}

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