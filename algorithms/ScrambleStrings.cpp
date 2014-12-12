//
//  ScrambleStrings.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//https://oj.leetcode.com/problems/scramble-string/ 
//Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
//To scramble the string, we may choose any non-leaf node and swap its two children.
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <climits>
#include <unordered_map>
using namespace std;
#include <assert.h>


class Solution2 {
    unordered_map<char, int> map;
    unordered_map<string, int> mem;
    
    bool StatsEqual()
    {
        for(pair<char, int> p : map)
        {
            if(p.second != 0)
                return false;
        }
        return true;
    };
    
    
    
public:
    Solution2(){map.reserve(128);};
    
    bool isScramble(string s1, string s2) {
        string key = s1+s2;
        if(mem.find(key) != mem.end())
            return mem[key];
            
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1!=len2)
        {
            mem[key] = false;
            return false;
        }
        
        //check if the two strings are the same
        if(s1==s2)
        {
            mem[key] = true;
            return true;
        }
        
        //check sequencial orders
        map.clear();
        for(int i=0; i<len1; i++)
        {
            map[s1[i]] += 1;
            map[s2[i]] -= 1;
            if(StatsEqual() && i<len1-1)
            {
                if( isScramble(s1.substr(0, i+1), s2.substr(0, i+1))
                        && isScramble(s1.substr(i+1), s2.substr(i+1)))
                {
                    mem[key] = true;
                    return true;
                }
            }
        }
        
        //check scrambled order
        map.clear();
        for(int i=0; i<len1; i++)
        {
            map[s1[i]] += 1;
            map[s2[len2-1-i]] -= 1;
            if(StatsEqual() && i<len1-1)
            {
                if( isScramble(s1.substr(0, i+1), s2.substr(len2-1-i))
                    && isScramble(s1.substr(i+1), s2.substr(0, len2-1-i)))
                {
                    mem[key] = true;
                    return true;
                }
            }
        }
        mem[key] = false;
        return false;
    }
};

int mainScr()
{
    Solution2 sol;
    cout << sol.isScramble("great", "regat") << endl;
    cout << sol.isScramble("hobobyrqd", "hbyorqdbo") << endl;
    cout << sol.isScramble("great", "egart") << endl;
    cout << sol.isScramble("great", "great") << endl;
    cout << sol.isScramble("", "") << endl;
    cout << sol.isScramble("", "a") << endl;
    return 0;
}