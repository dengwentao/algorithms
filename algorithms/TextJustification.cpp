//
//  TextJustification.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
#include <assert.h>

class Solution {
public:
    //if L is shorter than a word???
    // L is huge
    // no words, or single words.
    //each line is a word.
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int lineLen = L;
        vector<string> line;
        int spaceCount = 0;
        for(int i=0; i<words.size(); i++)
        {
            int wordLen = words[i].length();
            if(lineLen > wordLen + 1) //+1 ???
            {
                L -= (wordLen);
                line.push_back(words[i]);
                spaceCount++;
            }
            else
            {
                string s;
                int wordCount = line.size();
                spaceCount += L;
                res.push_back(s);
                i--;//???
                lineLen = L;
                line.clear();
                spaceCount = 0;
            }
            
        }
        return res;
    }
};

int mainJustify()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    Solution sol;
    for(string line : sol.fullJustify(words, 16))
        cout << line << endl;
    return 0;
}