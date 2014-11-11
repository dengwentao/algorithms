//
//  LongestIncSeq.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/10/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

//Given an array, find the longest sequence that is increasing.

#include <iostream>
#include <vector>
using namespace std;
#include <assert.h>

int buf[256];
int M(int index, const vector<int>& v)
{
    if(buf[index])
        return buf[index];

    int max = 0;
    for(int i=0; i<index; i++)
    {
        if(v[i]<=v[index])
        {
            int m = M(i, v);
            if(m>max)
                max = m;
        }
    }
    
    buf[index] = max + 1;
    return buf[index];
}

int LongestIncSeq(const vector<int>& v)
{
    int max = 0;
    for(int i=0; i<v.size(); i++)
    {
        int m = M(i, v);
        if(max<m)
            max = m;
    }
    return max;
}

int mainLInc()
{
    memset(buf, 0, sizeof(buf));
    buf[0] = 1;
    int a[] = {2,5,9,1,4,2,9,11,3};
    int size = sizeof(a)/sizeof(a[0]);
    vector<int> v(a, a+size);
    cout << LongestIncSeq(v) << endl;
    int* p = buf;
    while(*p)
    {
        cout << *p << ' ';
        p++;
    }
    cout << endl;
    return 0;
}