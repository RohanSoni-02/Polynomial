//
//  BernsteinBasisPolynomial.cpp
//  ProblemSet1
//
//  Created by Rohan Soni on 19/3/2022.
//

#include <stdio.h>
#include "BernsteinBasisPolynomial.h"
#include <cmath>

BernsteinBasisPolynomial:: BernsteinBasisPolynomial( unsigned int aV, unsigned int aN): fFactor(aN,aV)
{}

double BernsteinBasisPolynomial::operator()(double aX) const
{
    double Result;
    Result = fFactor() * (pow(aX, fFactor.getK())) * (pow((1-aX),fFactor.getN()-fFactor.getK()));
    return Result;
}
