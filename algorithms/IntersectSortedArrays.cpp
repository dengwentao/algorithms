//
//  IntersectSortedArrays.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/2/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;

void Intersect(int A[], int sizeA, int B[], int sizeB)
{
    int p=0, q=0;
    while(p<sizeA && q<sizeB)
    {
        if(A[p]==B[q]) // asumming no dup.
        {
            cout << A[p] << ' ';
            p++;
            q++;
        }
        else if(A[p]<B[q])
            p++;
        else
            q++;
    }
    cout << endl;
}

//Find target in array C  between indexes start and end.
//both indexes are inclusive
//return true if found and pos point to target; else return false and pos points to the elem just smaller than target. pos is -1 if none elem is just smaller.
bool find(int C[], int start, int end, int target, int& pos)
{
    while(start<=end)
    {
        int med = (start + end)/2;
        if(C[med] < target)
            return find(C, med+1, end, target, pos);
        else if(C[med] > target)
            return find(C, start, med-1, target, pos);
        else
        {
            pos = med;
            return true;
        }
    }
    pos = end;
    return false;
}

//indexes are inclusive // wrong
void Intersect2(int A[], int aStart, int aEnd, int B[], int bStart, int bEnd)
{
    int pos = 0;
    while(aStart<=aEnd && bStart<=bEnd)
    {
        int med = (aStart+aEnd)/2;
        if(find(B, bStart, bEnd, A[med], pos))
        {
            cout << A[med] << ' ';
            Intersect2(A, aStart, med-1, B, bStart, pos-1);
            Intersect2(A, med+1, aEnd, B, pos+1, bEnd);
        }
        else
        {
            Intersect2(A, aStart, med-1, B, bStart, pos);
            Intersect2(A, med+1, aEnd, B, pos, bEnd);
        }
    }
}

int mainInter()
{
    int A[] = {2,3,5,7,11,16,19};
    int sizeA = sizeof(A)/sizeof(A[0]);
    int B[] = {1,3,5,7,9,11,13,15,17,19,21};
    int sizeB = sizeof(B)/sizeof(B[0]);
    
    Intersect(A, sizeA, B, sizeB);
    Intersect2(A, 0, sizeA-1, B, 0, sizeB-1);
    return 0;
}