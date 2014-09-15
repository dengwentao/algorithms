//
//  MaxGapIncr.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/10/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//  Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].


#include <iostream>
#include <map>
using namespace std;
#include <assert.h>
#include "MaxGapIncr.h"

int MaxGap(int* a, int size)
{
    assert(a && size>1);
    // Make pairs and sort first.
    multimap<int, int> mappings;
    for(int i=0; i<size; i++)
        mappings.insert(make_pair(a[i], i));

    int maxGap = 0;
    int end = 0;
    for(multimap<int, int>::const_reverse_iterator rit=mappings.rbegin(); rit!=mappings.rend(); ++rit)
    {
        if(end > rit->second)
        {
            int gap = end - rit->second;
            if(maxGap < gap && a[end]!=rit->first) // 2nd condition to avoid dups
                maxGap = gap;
        }
        else
            end = rit->second;
    }
    return maxGap;
}

int mainMaxGap()
{
    int a[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int max = MaxGap(a, sizeof(a)/sizeof(a[0]));
    cout << "Max gap is " << max << endl;
    return 0;
}
