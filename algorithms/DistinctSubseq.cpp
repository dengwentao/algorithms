//
//  DistinctSubseq.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/1/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

//Given a string S and a string T, count the number of distinct subsequences of T in S.
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//Here is an example:
//S = "rabbbit", T = "rabbit"
//Return 3.

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
    
    int** Mem;
    void initMem(int row, int col)
    {
        Mem = new int* [row+1];
        for(int i=0; i<row+1; i++)
        {
            Mem[i] = new int [col+1];
            memset(Mem[i], 0xFF, sizeof(int)*(col+1));
        }
        memset(Mem[0], 0, sizeof(int)*(col+1));
        for(int i=0; i<col+1; i++)
            Mem[i][0] = 1;
    }
    
    void displayMem(int row, int col)
    {
        for(int i=0; i<row+1; i++)
        {
            for(int j=0; j<col+1; j++)
                cout << Mem[i][j] << '\t';
            cout << endl;
        }
    }
    
    int& mem(int i, int j)
    {
        return Mem[i+1][j+1];
    }
 
    int C(const string& S, const string& T, int i, int j) {
        if(mem(i, j) != -1)
            return mem(i, j);
        if(i==0 && j==0)
        {
            if(S[0]==T[0])
                mem(0,0) = 1;
            else
                mem(0,0) = 0;
            return mem(0,0);
        }
        if(S[i]==T[j])
            mem(i, j) = C(S, T, i-1, j-1) + C(S, T, i-1, j);
        else
            mem(i, j) = C(S, T, i-1, j);
        return mem(i, j);
    }
    
    int numDistinct(string S, string T) {
        if(S.length()<T.length() || S.length()==0)
            return 0;
        initMem(S.length(), T.length());
        return C(S, T, S.length()-1, T.length()-1);
    }
};

int mainDiseq()
{
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    cout << sol.numDistinct(s, t) << endl;
    sol.displayMem(s.length(), t.length());
    return 0;
}