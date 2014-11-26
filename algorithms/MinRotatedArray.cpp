//
//  MinRotatedArray.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/14/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Suppose a sorted array is rotated at some pivot unknown to you beforehand. Dup is allowed.

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    //return index of min in range [low, high]
    int smallest(const vector<int>& v, int low, int high)
    {
        if(low+1==high)
            return v[low]<=v[high] ? low : high;
        int med = low + (high-low)/2;
        if(v[low]<v[high])
            return low;
        else if(v[high]<v[low])
        {
            if(v[med]<=v[high])
                return smallest(v, low, med);
            else if(v[low]<=v[med])
                return smallest(v, med, high);
        }
        else//if v[high]==v[low]
        {
            return smallest(v, low+1, high);
        }
        return -1;//not possible
    }
    
    int findMin(vector<int> &num) {
        if(num.size()==0)
            return -2;
        if(num.size()==1)
            return num[0];
        int index_min = smallest(num, 0, num.size()-1);
        return num[index_min];
    }
};

//////////////////
// Normal bin-search
int BiSearch(const vector<int>& v, int low, int high, int target)
{
    if(v.size()==0)
        return -1;
    if(low==high)
        return v[low]==target ? low : -1;
    int med = low + (high-low)/2;
    if(v[med]<target)
        return BiSearch(v, med+1, high, target);
    else if(v[med]>target)
        return BiSearch(v, low, med-1, target);
    else
        return med;
}

// Find index of a given value in a rotated array
int FindTarget(const vector<int>& v, int low, int high, int target)
{
    if(v.size()==0)
        return -1;
    if(low==high)
        return v[low]==target ? low : -1;
    int med = low + (high-low)/2;
    if(v[low]<=v[med])//left part is in order
    {
        if(v[low]<=target && target<=v[med])
            return BiSearch(v, low, med, target);
        else
            return FindTarget(v, med+1, high, target);
    }
    if(v[med]<=v[high])//righ part is in order
    {
        if(v[med]<=target && target<=v[high])
            return BiSearch(v, med, high, target);
        else
            return FindTarget(v, low, med-1, target);
    }
    return -1;//not possible
    
}

//////////////////

int mainRotate()
{
    int a[] = {9, 9, 8, 8, 8, 9};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.findMin(v) << endl;
    cout << FindTarget(v, 0, v.size()-1, 8) << endl;
    return 0;
}