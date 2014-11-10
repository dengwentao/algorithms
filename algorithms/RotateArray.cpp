//
//  RotateArray.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/1/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
/*
 Rotate a one-dimensional array of n elements to the right by k steps.
 For instance, with n=7 and k=3, the array {a, b, c, d, e, f, g} is rotated to {e, f, g, a, b, c, d}.
 */

#include <iostream>
using namespace std;
#include <assert.h>

//Rotate array A for k steps.
void Rotate(int A[], int size, int k)
{
    if(size<2 || k<1)
        return;
    k = k % size;
    int count = 0;
    for(int i=0; i<k; i++)
    {
        int p = i;
        int tmp1 = A[i];
        int tmp2 = A[i];
        do{
            p = (p+k)%size;
            tmp2 = A[p];
            A[p] = tmp1;
            count ++;
            if(count==size) //
                return;
            tmp1 = tmp2;
        }while(p!=i);
    }
}

// reverse array from index i to j (inclusive)
void Reverse(int A[], int i, int j)
{
    while(i<j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }
}

void Rotate2(int A[], int size, int k)
{
    if(size<2 || k<1)
        return;
    k = k % size;
    Reverse(A, 0, size-1);
    Reverse(A, 0, k-1);
    Reverse(A, k, size-1);
}

int mainRotateArray()
{
    int A[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(A)/sizeof(A[0]);
    Rotate2(A, size, 10);
    for(int i=0; i<size; i++)
        cout << A[i] << ' ';
    cout << endl;
    return 0;
}