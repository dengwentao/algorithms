//
//  Painter.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
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
int B[N+1][K+1];

//return the sum of elements Ai to Aj (both inclusive).
int sum(int i, int j)
{
    assert(i>=0 && i<N && j>=i && j<N);
    int s = 0;
    for(int k=i; k<=j; k++)
        s += A[k];
    return s;
}

//i is number of elements while k is number of partitions.
int S(int i, int k)
{
    cout << i << ' ' << k << endl;
    assert(i>0 && i<=N && k>0 && k<=K);
    
    // if has cached result
    if(B[i][k]!=-1)
        return B[i][k];
    
    //only 1 partition for first i elements
    if(k==1 || i==1)
    {
        B[i][k] = sum(0, i-1);
        return B[i][k];
    }
    
    // partion first j elems into k-1 partitions and remainder into 1 partition, and then find min
    int min = INT_MAX;
    for(int j=1; j<i; j++)
    {
        int a = S(j, k-1);
        int b = sum(j, i-1);
        int max = (a>b ? a : b);
        if(min > max)
            min = max;
    }
    B[i][k] = min;
    return B[i][k];
}

int mainPainter()
{
    for(int i=0; i<N+1; i++)
        for(int j=0; j<K+1; j++)
            B[i][j] = -1;
    cout << S(N, K) << endl;
    for(int i=0; i<N+1; i++)
    {
        for(int j=0; j<K+1; j++)
            cout << B[i][j] << "\t\t";
        cout << endl;
    }
    return 0;
}