//
//  TriSumClosest.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/13/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the gap. You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#include <assert.h>

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int gap=INT_MAX, x=0, y=0, z=0;
        for(int i=0; i<num.size(); i++)
        {
            int a=0, b=0;
            int dif = TwoSumClosest(num, target-num[i], a, b, i);
            if(dif < gap)
            {
                gap = dif;
                x = a;
                y = b;
                z = num[i];
            }
        }
        cout << x << ' ' << y << ' ' << z << endl;
        
        return gap;
    }
    
    //input a sorted array and a target. Find two sum up to target with closest gap.
    //return the closest gap.
    //avoid index because it's already used.
    int TwoSumClosest(const vector<int> &num, int target, int& a, int& b, int index)
    {
        int i=0;
        int j=num.size()-1;
        int gap = INT_MAX;
        while(i<j)
        {
            if(i==index)
            {
                i++;
                continue;
            }
            if(j==index)
            {
                j--;
                continue;
            }
            int sum = num[i] + num[j];
            int dif = abs(target-sum);
            if(dif < gap)
            {
                gap = dif;
                a = num[i];
                b = num[j];
            }
            if(sum<target)
                i++;
            else if(sum>target)
                j--;
            else
            {
                break;
            }
        }
        return gap;
    }
    
    
};


int main3SumClosest()
{
    int a[] = {5, 1, 7, -2, -5, 9, 8, 4};
    int target = 23;
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    Solution sol;
    cout << sol.threeSumClosest(v, target) << endl;
    return 0;
}