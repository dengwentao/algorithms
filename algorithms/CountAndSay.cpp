//
//  CountAndSay.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/12/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/*
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
 */

#include <iostream>
using namespace std;
#include <assert.h>

string CountAndSay(string s)
{
    string res;
    char what=s[0];
    int count=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==what)
            count++;
        else
        {
            res.push_back(count+'0');
            res.push_back(what);
            what = s[i];
            count = 1;
        }
    }
    res.push_back(count+'0');
    res.push_back(what);
    return res;
}

int mainSay()
{
    string cur = "1";
    for(int i=2; i<17; i++)
    {
        cur = CountAndSay(cur);
        cout << cur << endl;
    }
    return 0;
}