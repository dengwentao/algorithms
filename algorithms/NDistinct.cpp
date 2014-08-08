//
//  n_distinct.cc
//  InterviewExcercises
//
//  Created by Wentao Deng on 8/6/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//  Given a string, find longest substring with n distinct characters.


#include <iostream>
#include <unordered_map>
using namespace std;
#include <assert.h>
#include "NDistinct.h"

//if s is empty, 1 char, or dup of 1 char, if n is longer than s.
void DistinctN(const char* s, int n)
{
    assert(s && n>0 && strlen(s)>=n);
    unordered_map<char, int> h;
    int maxStart = 0;
    int maxEnd = 0; //inclusive
    int winStart = 0;
    int winEnd = 0; //inclusive
    int distinct = 1;
    h[s[winEnd]] += 1;
    
    //terminate as soon as winEnd expands to last char because window won't be longer.
    while(winEnd < strlen(s)-1)
    {
        cout << "start=" << winStart << " end=" << winEnd << " distinct=" << distinct << endl;
        if(distinct < n)
        {   // if we can expand
            winEnd ++;
            if(h[s[winEnd]]==0)
                distinct ++;
            h[s[winEnd]] += 1;
        }
        else if (distinct == n)
        {
            if(h[s[winEnd+1]]!=0)
            {   //if we can still expand
                winEnd ++;
                h[s[winEnd]] += 1;
            }
            else
            {
                //if we cannot expand, record and shrink
                if(winEnd-winStart > maxEnd-maxStart)
                {
                    maxEnd = winEnd;
                    maxStart = winStart;
                }
                //shrink
                h[s[winStart]] -= 1;
                if(h[s[winStart]]==0)
                    distinct --;
                winStart ++;
            }
        }
        else
            assert(false);
    }
    
    for(int i=maxStart; i<=maxEnd; i++)
        cout << s[i] << " ";
    cout << endl;
}

int mainx()
{
    const char * s =  "Hello world!";
    DistinctN(s, 4);
    return 0;
}