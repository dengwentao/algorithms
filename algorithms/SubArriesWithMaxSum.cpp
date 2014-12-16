//
//  SubArriesWithMaxSum.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/9/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
/*
 Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
 The number in each subarray should be contiguous.
 Return the largest sum.
 Note: The subarray should contain at least one number
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
#include <assert.h>

class Solution2 {
    int** mem;
    int** m2;
    vector<int> v;
public:
    
    //the largest sum starting from index j to n.
    //when it's all negative, keep the negative value.
    int LargestSum(int j, int n)
    {
        //assert(j>=0 && j<=n && n<v.size());
        if(m2[j][n]!=-1)
            return m2[j][n];
        
        int max_so_far = v[j];
        int cur_max = v[j];
        for(int i=j+1; i<=n; i++)
        {
            cur_max = (cur_max+v[i]<v[i] ? v[i] : cur_max+v[i]);
            max_so_far = (max_so_far>cur_max ? max_so_far : cur_max);
        }
        return max_so_far;
    }
    
    //partition 0 to i into k partitions and return the largest sum.
    //To do this, separate 0 to i into two parts, one from 0 to j and another j+1 to i.
    //the first part is sub-divided into k-1 partitions and the 2nd part another.
    int M(int i, int k)
    {
        assert(i >= k-1);
        if(mem[i][k]!=-1)
            return mem[i][k];
        
        if(k==1)
        {
            mem[i][k] = LargestSum(0, i);
            return mem[i][k];
        }

        int max = INT_MIN;
        for(int j=k-2; j<=i-1; j++)
        {
            int sum = M(j, k-1) + LargestSum(j+1, i);
            if(max < sum)
                max = sum;
        }
        mem[i][k] = max;
        return max;
    }
    
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxKSubArrays(vector<int> nums, int k) {
        mem = new int* [nums.size()];
        for(int i=0; i<nums.size(); i++)
        {
            mem[i] = new int[k+1];
            memset(mem[i], 0xFF, (k+1)*sizeof(int));
        }
        m2 = new int* [nums.size()];
        for(int i=0; i<nums.size(); i++)
        {
            m2[i] = new int [nums.size()];
            memset(m2[i], 0xFF, nums.size()*sizeof(int));
        }
        v = nums;
        return M(nums.size()-1, k);
    }
    
    void display(int k)
    {
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<=k; j++)
                cout << mem[i][j] << '\t';
            cout << endl;
        }
    }
};


int mainSubMax()
{
    vector<int> nums = {3, -2, 8, -9, 1, 3};//{-1,-2,-3,-100,-1,-50};//{5, 4};//
    int k=3;
    Solution2 sol;
    cout << sol.maxKSubArrays(nums, k) << endl;
    //for(int i=0; i<nums.size(); i++)
    //    cout << sol.LargestSum(i, nums.size()-1) << endl;
    sol.display(k);
    return 0;
}