//
//  painters2.cpp
//  algorithms
//
//  Created by Wentao Deng on 10/23/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/*
 You have to paint N boards of length {A0, A1, A2 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint continuous sections of board, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}
 */

#include <climits>
#include <iostream>
using namespace std;
#include <assert.h>

const int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
const int K = 3;
const int N = sizeof(A)/sizeof(A[0]);

// sum of A
int sum()
{
    int sum = 0;
    for(int i=0; i<N; i++)
        sum += A[i];
    return sum;
}

// max of A[]
int max()
{
    int max = 0;
    for(int i=0; i<N; i++)
        if(max < A[i])
            max = A[i];
    return max;
}

// return how many painters are needed when max work a painter will do is m.
int painters(int m)
{
    int c = 1;
    int w = 0;
    for(int i=0; i<N; i++)
    {
        w += A[i];
        if(w>m)
        {
            c++;
            w = A[i];
        }
    }
    return c;
}

int mainP2()
{
    int low = max();
    int high = sum();
    while(low<high)
    {
        cout << low << '\t' << high << endl;
        int med = (low + high)/2;
        int p = painters(med);
        if(p<=K)
            high = med;
        else
            low = med+1; // need more than K painters, so give up med.
    }
    cout << low << endl;
    return low;
}