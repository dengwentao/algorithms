//
//  RangeOfDups.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/11/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;
#include <assert.h>

int R[] = {2,3,3,3,3,5,7,11,14,14,14};
int size = sizeof(R)/sizeof(R[0]);
//Test none, only one, all the same, two, two sames, find non-exist, find first/last one

//search array R from index p to q for value v.
//return the position of the first v if front is true or last if false.
int Position(int p, int q, int v, bool front)
{
    assert(p<=q);
    if(p==q)
    {
        if(R[p]==v)
            return p;
        else
            return -1; //not found
    }
    //we need this to avoid stuck when p and q are neighbors. That's because we don't have med+1 or med-1 from some conditions.
    if(p+1==q)
    {
        if(R[p]==v&&(front||(!front&&R[q]!=v)))
            return p;
        else if(R[q]==v&&(!front||(front&&R[p]!=v)))
            return q;
        else
            return -1;
    }
    int med = p + (q-p)/2;
    if(R[med]<v)
        return Position(med+1, q, v, front);
    else if(R[med]>v)
        return Position(p, med-1, v, front);
    else
    {
        if(front)
            return Position(p, med, v, front);
        else
            return Position(med, q, v, front);
    }
}

int mainDups()
{
    cout << Position(0, size-1, 3, true) << endl;
    cout << Position(0, size-1, 3, false) << endl;
    return 0;
}