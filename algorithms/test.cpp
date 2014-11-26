//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//We need to cut a wood bar with length L. Cutting positions are in an array A[1..N]. The cost of cutting is current bar length. Find the way to yield out lowest cut.


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
#include <assert.h>

int Q[] = {0, 5, 6, 7, 12};
int N = sizeof(Q)/sizeof(Q[0]);
int **Mem;
void InitMem()
{
    Mem = new int*[N];
    for(int i=0; i<N; i++)
    {
        Mem[i] = new int[N];
        memset(Mem[i], 0, N*sizeof(int));
    }
}

//input the index of start position and end position
int Cut(int start, int end)
{
    if(Mem[start][end]!=0)
        return Mem[start][end];
    if(end-start==1)
        return 0;
    assert(N>=end&&end>start && start>=0);
    int min=INT_MAX;
    for(int i=start+1; i<end; i++)
    {
        int cost = Cut(start, i) + Cut(i, end);
        if(cost<min)
            min = cost;
    }
    Mem[start][end] = min + Q[end] - Q[start];
    return Mem[start][end];
}

int main()
{
    InitMem();
    cout << Cut(0, N-1) << endl;
    return 0;
}