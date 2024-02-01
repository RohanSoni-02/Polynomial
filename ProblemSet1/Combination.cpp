//
//  Combination.cpp
//  ProblemSet1
//
//  Created by Rohan Soni on 19/3/2022.
//

#include <stdio.h>
#include "Combination.h"
#include <cstddef>
#include <cmath>

using namespace std;

Combination::Combination(size_t aN, size_t aK)
{
    fN = aN;
    fK= aK;
}

size_t Combination::getN() const
{
    return fN;
}

size_t Combination::getK() const
{
    return fK;
}

unsigned long long Combination::operator()() const
{
    unsigned long long Result = 1;
    for (size_t i=1; i<=fK; i++)
    {
        Result = (Result * (fN-(i-1)))/i;
    }
    
    return Result;
}




