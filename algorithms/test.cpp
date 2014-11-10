//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
#include <assert.h>

//Write a function that takes in a sentence, and returns the words that repeat.

enum State {start, word, space};
vector<string> GetAllWords(const string& s)
{
    vector<string> result;
    State st = start;
    const char* p = s.c_str();
    const char* q = p;
    while(*p)
    {
        switch(st)
        {
            case start:
                if(isalpha(*p))
                    st = word;
                else
                    st = space;
                break;
            case word:
                if(!isalpha(*p))
                {
                    st = space;
                    string s;
                    while(q!=p)
                    {
                        s.push_back(*q);
                        q++;
                    }
                    result.push_back(s);//chars between p and q
                }
                break;
            case space:
                if(isalpha(*p))
                {
                    st = word;
                    q = p;
                }
                break;
        }
        p++;
    }
    return result;
}

unordered_set<string> FindRepeatedWords(const string& s)
{
    unordered_set<string> words;
    unordered_set<string> result;
    vector<string> v = GetAllWords(s);
    for(vector<string>::const_iterator it=v.begin(); it!=v.end(); ++it)
    {
        if(words.find(*it)!=words.end())
        {
            result.insert(*it);
        }
        else
        {
            words.insert(*it);
        }
    }
    return result;
}

int mainXX()
{
    string s = "I know, I know. Hello is not a hello but a hell, you know?";
    unordered_set<string> rep = FindRepeatedWords(s);
    for(unordered_set<string>::const_iterator it=rep.begin(); it!=rep.end(); ++it)
        cout << *it << endl;
    return 0;
}