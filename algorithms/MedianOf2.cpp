//
//  MedianOf2.cpp
//  algorithms
//
//  Created by Wentao Deng on 10/28/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/*
    There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
    The overall run time complexit should be O(log (m+n)).
 */
#include <climits>
#include <iostream>
using namespace std;
#include <assert.h>

int AA[] = {1,4,6,9,17,18,31,52};
const int SIZE_A = sizeof(AA)/sizeof(AA[0]);
int BB[] = {1,4,6,9,12,15,18,26,29,37,39,43, 49, 54};
const int SIZE_B = sizeof(BB)/sizeof(BB[0]);


//Handles special case where one array has only 1 elem. Here b is the single element.
int MedOf2Base1(int A[], int a1, int a2, int b)
{
    int m = (a1+a2)/2;
    if((a2-a1)%2==0)//odd elems, med elem is the same even though there's an extra elem.
        return A[m];
    if(A[m]<b)
        return A[m+1];
    else if(A[m]>=b)
        return A[m];
    return -1;
}

//Handles special case where one array has only 2 elems. Here b1 and b2 are elements of the array.
int MedOf2Base2(int A[], int a1, int a2, int b1, int b2)
{
    int m = (a1+a2)/2;
    if(b1<A[m] && A[m]<b2)
        return A[m];
    if((a2-a1)%2==0)//odd elems
    {
        if(b1==A[m] || b2==A[m])
            return A[m];
        if(b1>A[m])
            return (A[m+1]>b1 ? b1 : A[m+1]);
        if(b2<A[m])
            return (A[m-1]<b2 ? b2 : A[m-1]);
    }
    else
    {
        if(A[m]>=b2)
            return A[m]; // med is in the shorter part, so even if we add two more the med is the same.
        if(A[m]<b1)
            return (A[m+1]<b1 ? A[m+1] : b1);
        if(A[m]==b1)
            return (A[m+1]<b2 ? A[m+1] : b1);
    }
    return -1;
}

// a1 is start index in A and a2 is end index.
int MedOf2(int A[], int a1, int a2, int B[], int b1, int b2)
{
    assert(a1>=0 && a1<=a2 && a2<SIZE_A && b1>=0 && b1<=b2 && b2<SIZE_B);
    
    if(a1==a2)
        return MedOf2Base1(B, b1, b2, A[a1]);
    else if(b1==b2)
        return MedOf2Base1(A, a1, a2, B[b1]);
    else if(a1+1==a2)
        return MedOf2Base2(B, b1, b2, A[a1], A[a2]);
    else if(b1+1==b2)
        return MedOf2Base2(A, a1, a2, B[b1], B[b2]);
    
    int idxA = (a1+a2)/2;
    int medA = A[idxA];
    int idxB = (b1+b2)/2;
    int medB = B[idxB];
    
    if(medA < medB)
    {
        if(a2-a1<=b2-b1)
            return MedOf2(A, idxA, a2, B, b1, b2-idxA+a1);
        else
            return MedOf2(A, a1+b2-idxB, a2, B, b1, idxB);
    }
    else if(medA > medB)
    {
        if(a2-a1<=b2-b1)
            return MedOf2(A, a1, idxA, B, b1+a2-idxA, b2);
        else
            return MedOf2(A, a1, a2+b1-idxB, B, idxB, b2);
    }
    else
        return medA;
}

int main()
{
    cout << MedOf2(AA, 0, SIZE_A-1, BB, 0, SIZE_B-1)<<endl;
}