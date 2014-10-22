//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <assert.h>

typedef unsigned int uint;
uint swapBits(uint x, uint i, uint j) {
    uint lo = ((x >> i) & 1);
    uint hi = ((x >> j) & 1);
    if (lo ^ hi) {
        x ^= ((1U << i) | (1U << j));
    }
    return x;
}

uint reverseXor(uint x) {
    uint n = sizeof(x) * 8;
    for (uint i = 0; i < n/2; i++) {
        x = swapBits(x, i, n-i-1);
    }
    return x;
}

void swap(unsigned int& x, int i, int j)
{
    unsigned int a = x & (0x1<<i);
    unsigned int b = x & (0x1<<j);
    if(a^b)
    {
        x = (x ^ (0x1<<i)) ^ (0x1<<j);
    }
}

unsigned int rev(unsigned int x)
{
    int n = sizeof(x)*8;//how many bits
    for(int i=0; i<n/2; i++)
    {
        swap(x, i, n-i-1);
    }
    return x;
}

int mainXX()
{
    unsigned int x = 567;
    unsigned int y = reverseXor(x);
    unsigned int z = rev(x);
    cout << x << ' ' << y << ' ' << z << endl;
    
    
    return 0;
}