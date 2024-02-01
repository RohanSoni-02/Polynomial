//
//  PolynomialPS1.cpp
//  ProblemSet1
//
//  Created by Rohan Soni on 19/3/2022.
//

#include <stdio.h>
#include "Polynomial.h"
#include <cmath>

using namespace std;

Polynomial::Polynomial() :
    fDegree(0)
{
    for ( size_t i = 0; i <= MAX_DEGREE; i++ )
    {
        fCoeffs[i] = 0.0;
    }
}

bool Polynomial::operator==( const Polynomial& aRHS ) const
{
    bool Result = fDegree == aRHS.fDegree;
    
    for ( size_t i = 0; Result && i <= fDegree; i++ )
    {
        if ( fCoeffs[i] != aRHS.fCoeffs[i] )
        {
            Result = false;
        }
    }
    
    return Result;
}

Polynomial Polynomial::operator*( const Polynomial& aRight ) const
{
    // C = A * B
    
    Polynomial Result;
    
    Result.fDegree = fDegree + aRight.fDegree;
    
    for ( size_t i = 0; i <= fDegree; i++ )
    {
        for ( size_t j = 0; j <= aRight.fDegree; j++ )
        {
            Result.fCoeffs[i+j] += fCoeffs[i] * aRight.fCoeffs[j];
        }
    }
    
    return Result;
}

ostream& operator<<( ostream& aOStream, const Polynomial& aObject )
{
    bool lMustPrintPlus = false;
    
    for ( int i = static_cast<int>(aObject.fDegree); i >= 0; i-- )
    {
        if ( aObject.fCoeffs[i] != 0.0 )
        {
            if ( lMustPrintPlus )
            {
                aOStream << " + ";
            }
            else
            {
                lMustPrintPlus = true;
            }
            
            aOStream << aObject.fCoeffs[i] << "x^" << i;
        }
    }
    
    return aOStream;
}
                
istream& operator>>( istream& aIStream, Polynomial& aObject )
{
    // read degree
    size_t lDegree;
    
    aIStream >> lDegree;

    aObject.fDegree = lDegree <= MAX_POLYNOMIAL ? lDegree : MAX_POLYNOMIAL;

    // read coefficients (assume sound input)
    for ( int i = static_cast<int>(aObject.fDegree); i >= 0; i-- )
    {
        aIStream >> aObject.fCoeffs[i];
    }

    return aIStream;
}

double Polynomial::operator()(double aX) const
{
    double Result = 0.0;
    for (int i=0; i<=fDegree; i++) {
        Result += fCoeffs[i] * pow(aX, i);
    }
    return Result;
}

Polynomial Polynomial::getDerivative() const
{
    Polynomial Result;
    if (fDegree == 0)
    {
        return Result;
    }
    else
    {
        for (int i = static_cast<int>(fDegree); i > 0; i--)
        {
            Result.fCoeffs[i - 1] = fCoeffs[i] * (i);
        }
        if (fDegree - 1 >= 0)
        {
            Result.fDegree = fDegree - 1 <= MAX_POLYNOMIAL ? fDegree - 1 : MAX_POLYNOMIAL;
        }
        else
        {
            Result.fDegree = 0;
        }
    }
    return Result;
}
 
Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial Result;
        for (int i = 0; i <= fDegree; i++) {
            Result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
        }
        Result.fDegree = fDegree + 1;
    return Result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
    double Result= 0.0;
    Polynomial defint =getIndefiniteIntegral();
    Result = defint(aXHigh)-defint(aXLow);
    return Result;
}








