//
//  MaxProd.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/20/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    //max production in the range (start, end), both ends exclusive. This range has no 0, but could have negs.
    int maxProd(int A[], int start, int end)
    {
        if(end-start<2)
            return 0;
        unordered_map<int, int> negs; //record index of neg values and its left prod.
        int prod = 1;
        for(int i=start+1; i<end; i++)
        {
            if(A[i]<0)
            {
                negs[i] = prod;
            }
            prod *= A[i];
        }
        int max = INT_MIN;
        if(prod>0 || end-start==2)//array in format {-3}
            return prod;
        else
        {
            //There're odd count of negs, so divide on it.
            for(auto it=negs.begin(); it!=negs.end(); ++it)
            {
                int prod_left = it->second;
                max = max < prod_left ? prod_left : max;
                int prod_right = prod/(prod_left*A[it->first]);
                max = max < prod_right ? prod_right : max;
            }
        }
        return max;
    }
    
    //0, single A {-1/0/1}, {0,0,0}
    int maxProduct(int A[], int n) {
        int max = INT_MIN;
        int start=-1, end=-1;
        for(int i=0; i<n; i++)
        {
            if(A[i]==0)
            {
                start = end;
                end = i;
                int prod = maxProd(A, start, end);
                if(max<0)
                    max = 0;//because we have 0.
                if(max < prod)
                    max = prod;
            }
        }
        if(A[n-1]!=0)//need to check the tail
        {
            start = end;
            end = n;
            int prod = maxProd(A, start, end);
            if(max < prod)
                max = prod;
        }
        
        return max;
    }
};

int mainProd()
{
    int a[] = {2,3,-2,-4,-3,7,0,2,9,-1,6,0};
    Solution sol;
    cout << sol.maxProduct(a, sizeof(a)/sizeof(a[0])) << endl;
    return 0;
}