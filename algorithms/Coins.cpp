//
//  Coins.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// You are given a set of coins. Valus of coins are in set S.
// You have unlimited number of each coin.
// Find out how many ways we can use to change N cents.

#include <iostream>
using namespace std;
#include <assert.h>
#include "Coins.h"

int S[] = {5, 2, 1};

// m stands for index of coin.
// n is total value.
int ways(int m, int n)
{
    if(m==sizeof(S)/sizeof(S[0]) || n<0)
        return 0;
    if(n==0)
        return 1;
    return ways(m, n-S[m]) + ways(m+1, n);
}

// if no repeat allowed.
// m stands for index of coin.
// n is total value.
int SS[] = {5, 3, 2, 1};
int ways2(int m, int n)
{
    if(m==sizeof(SS)/sizeof(SS[0]) && n!=0)
        return 0;
    if(n==0)//found a solution
        return 1;
    else if(n<0)
        return 0;
    else
        return ways2(m+1, n-SS[m]) + ways2(m+1, n);
}

int mainCoins()
{
    cout << ways(0, 5) << endl;
    cout << ways2(0, 5) << endl;
    return 0;
}