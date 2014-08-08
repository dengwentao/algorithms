//
//  RainWater.cpp
//  algorithms
//
//  Created by Wentao Deng on 8/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//  Given an array of int values as board height. How much water can it hold?

#include <iostream>
using namespace std;
#include <assert.h>
#include "RainWater.h"

int main()
{
    int board[] = {3, 14, 5, 4, 9, 2, 3, 5, 2, 11};
    int size = sizeof(board)/sizeof(board[0]);
    int* leftMax = new int [size];
    int* rightMax = new int [size];
    
    int max=0;
    for(int i=0;i<size;i++)
    {
        leftMax[i] = max;
        if(board[i]>max)
            max = board[i];
    }
    
    max=0;
    for(int i=size-1;i>=0;i--)
    {
        rightMax[i] = max;
        if(board[i]>max)
            max = board[i];
    }
    
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        int level = (leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i]);
        if(level - board[i] >0)
            sum += (level - board[i]);
    }
    
    cout << sum << endl;
    
}