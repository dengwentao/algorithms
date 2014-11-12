//
//  MaxCommonSubString.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/11/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;
#include <assert.h>

int** mem=0;

int M(const string& s1, const string& s2, int i, int j)
{
    if(i<0 || j<0)
        return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];
    if(s1[i]==s2[j])
        mem[i][j] = 1+M(s1, s2, i-1, j-1);
    else
        mem[i][j] = 0;
    cout << i << ' ' << j << ' ' << mem[i][j] << endl;
    return mem[i][j];
}

int LongestCommonSubString(const string& s1, const string& s2)
{
    int max = 0;
    for(int i=0; i<s1.size(); i++)
        for(int j=0; j<s2.size(); j++)
        {
            int m = M(s1, s2, i, j);
            if(max < m)
                max = m;
        }
    return max;
}

int mainSubstring()
{
    string s1 = "aacd";
    string s2 = "aaac";
    mem = new int* [s1.size()];
    for(int i=0; i<s1.size(); i++)
    {
        mem[i] = new int[s2.size()];
        memset(mem[i], 0xFF, s2.size()*sizeof(int));
    }
    cout << LongestCommonSubString(s1, s2) << endl;
    return 0;
}