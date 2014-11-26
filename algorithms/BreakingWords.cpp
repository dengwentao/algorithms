//
//  BreakingWords.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/26/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
//Return all such possible sentences.
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//A solution is ["cats and dog", "cat sand dog"].

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
#include <assert.h>

class Solution {
    //memorization: for string after index, return corresponding list of broken words.
    unordered_map<int, vector<string>> mem;
    
    //For input string after index, return a list of sentences with broken words.
    vector<string> wordBreak(const string& input, int index, unordered_set<string> &dict)
    {
        if(mem.find(index)!=mem.end())
            return mem[index];
        vector<string> res;
        for(int i=index; i<input.length(); i++)
        {
            string sub = input.substr(index, i-index+1);
            if(dict.find(sub)!=dict.end())
            {
                if(i==input.length()-1) //if the input after index is in dict
                {
                    res.push_back(sub);
                }
                else
                {
                    vector<string> remainder = wordBreak(input, i+1, dict);
                    if(!remainder.empty())
                    {
                        for(const string& s :remainder)
                            res.push_back(sub+' '+s);
                    }
                }
            }
        }
        mem[index] = res;
        return res; //this could be empty
    }
    
public:
    //empty, single char, with space, exact in dict.
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreak(s, 0, dict);
    }
};

int mainBreak()
{
    string input = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog", "catsanddog"};
    Solution sol;
    vector<string> res = sol.wordBreak(input, dict);
    for(const string& s : res)
        cout << s << endl;
    return 0;
}