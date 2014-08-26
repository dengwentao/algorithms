//
//  PrintDiag.cpp
//  algorithms
//
//  Created by Wentao Deng on 8/26/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;
#include <assert.h>
#include "PrintDiag.h"

const int M = 4;
const int N = 3;

int A[M][N] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

void PrintDiag(int i, int j)
{
    while(i<M && j<N && i>=0 && j>=0)
    {
        cout << A[i][j] << ' ';
        i--;
        j++;
    }
    cout << endl;
}

// return -1 if invalid.
int PrintSpiral(int x)
{
    int m = M - 2*x;
    int n = N - 2*x;
    if(m<=0 || n<=0)
        return -1;
    for(int i=0; i<n; i++)
        cout << A[x][x+i] << ' ';
    for(int i=1; i<m-1; i++)
        cout << A[x+i][x+n-1] << ' ';
    for(int i=n-1; i>=0&&m>1; i--)
        cout << A[x+m-1][x+i] << ' ';
    for(int i=m-2; i>0&&n>1; i--)
        cout << A[x+i][x] << ' ';
    return 0;
}

int main()
{
    cout << "Print matrix in diag" << endl;
    for(int i=0; i<M; i++)
        PrintDiag(i, 0);
    for(int j=1; j<N; j++)
        PrintDiag(M-1, j);
    
    cout << "Now in spriral" << endl;
    for(int i=0; i< M; i++)
    {
        if(PrintSpiral(i)!=0)
            break;
        cout << endl;
    }
    
    return 0;
}
