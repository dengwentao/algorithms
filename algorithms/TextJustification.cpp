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
    
    //input words for 1 line. L is line max length.
    //return justified line.
    string justify(vector<string> &words, int L)
    {
        string res;
        if(words.back() == "$")
        {
            //the last line
            for(string word : words)
                res += word + ' ';
            res.erase(res.length()-3);
            for(int i=res.length(); i<L; i++)
                res += ' ';
        }
        else
        {
            int wordCount = words.size();
            int spaceCount = L;
            for(string word : words)
                spaceCount -= word.length();
            if(wordCount == 1)
            {
                res += words[0];
                for(int i=res.length(); i<L; i++)
                    res += ' ';
            }
            else
            {
                int avg = spaceCount / (wordCount-1); //if wordcont==1
                int extra = spaceCount % (wordCount-1);
                for(int i=0; i<wordCount; i++)
                {
                    res += words[i];
                    for(int j=0; j<avg; j++)
                        res += ' ';
                    if(i < extra)
                        res += ' ';
                }
                res.erase(res.length()-avg);
            }
        }
        return res;
    }
    
    //if L is shorter than a word???
    // L is huge
    // no words, or single words.
    //each line is a word.
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        vector<string> line; //words for this line so far
        line.push_back(words[0]);
        int length = words[0].length(); //line length so far
        for(int i=1; i<words.size(); i++)
        {
            if(length > L)
            {
                //cout << words[i-1] << "cannot be fit in." << endl;
                return res;
            }
            int wordLen = words[i].length();
            if(L >= 1 + wordLen + length)
            {
                length += wordLen + 1;
                line.push_back(words[i]);
            }
            else
            {
                // a new line. Output old and clear to input this word as new.
                string s = justify(line, L);
                //cout << s << endl;
                res.push_back(s);
                line.clear();
                line.push_back(words[i]);
                length = words[i].length();
            }
            
        }
        
        //To indicate the end.
        if(res.size() > 0)
            line.push_back("$");
        string s = justify(line, L);
        //cout << s << endl;
        res.push_back(s);
        return res;
    }
};

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    Solution sol;
    for(string line : sol.fullJustify(words, 16))
        cout << line+'$' << endl;
    return 0;
}