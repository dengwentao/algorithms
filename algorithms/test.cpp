//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//For example,
//Given [100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
#include <assert.h>


class Solution {
public:
    //empty,dup, neg
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        for(int n : num)
            set.insert(n);
        
        unordered_map<int, int> map; //maps between number can consequtive length.
        int max = 0;
        for(int n : num)
        {
            if(map.find(n)!=map.end())
                continue; //we've already met this.
            int len = 1;
            int m = n;
            while(set.find(++n)!=set.end())
            {
                if(map.find(n)!=map.end()) //already in map
                {
                    len += map[n];
                    break;
                }
                else
                    map[n] = ++len;
            }
            map[m] = len;
            if(len>max)
                max = len;
        }
        
        return max;
    }
};

int mainTest()
{
    vector<int> num = {5, 0, 100, 4, 200, 1, 1, 3, 2, -1};
    Solution sol;
    cout << sol.longestConsecutive(num) << endl;
    return 0;
}