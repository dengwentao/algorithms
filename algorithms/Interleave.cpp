//
//  Interleave.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/7/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <climits>
#include <unordered_map>
using namespace std;
#include <assert.h>


class Solution {
    int** mem;
public:
    bool intl(int i, int j, const string& s1, const string& s2, const string& s3)
    {
        if(i==-1)
            return (s2[j]==s3[j]);
        if(j==-1)
            return (s1[i]==s3[i]);
        if(mem[i][j]!=-1)
            return mem[i][j];
        assert(i>=0 && j>=0);
        mem[i][j] = ((intl(i-1, j, s1, s2, s3) && s1[i]==s3[i+j+1]) || (intl(i, j-1, s1, s2, s3) && s2[j]==s3[i+j+1]));
        return mem[i][j];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        mem = new int* [l1];
        for(int i=0; i<l1; i++)
        {
            mem[i] = new int [l2];
            memset(mem[i], 0xFF, l2*sizeof(int));
        }
        return intl(l1-1, l2-1, s1, s2, s3);
    }
};

int mainIntleave()
{
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";
    cout << sol.isInterleave("", "", "a") << endl;
    //cout << sol.isInterleave(s1, s2, "aadbbcbcac") << endl;
    //cout << sol.isInterleave(s1, s2, "aadbbbaccc") << endl;
    return 0;
}