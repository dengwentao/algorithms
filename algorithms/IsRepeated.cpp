//
//  IsRepeated.cpp
//  algorithms
//
//  Created by Wentao Deng on 10/29/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <climits>
#include <iostream>
using namespace std;
#include <assert.h>

//s is 0, 1 char, pattern len > 1
bool IsRepeated(const char* s)
{
    if(s==0)
        return false;
    if(strlen(s)<2)
        return false;
    const char* p = s;
    const char* q = s+1;
    while(*q!=0)
    {
        cout << "p=" << p-s << " q=" << q-s << endl;
        const char* p1 = p;
        const char* q1 = q;
        while(*p1 == *q1)
        {
            p1++;
            q1++;
        }
        if(*q1==0)
        {
            return q-p!=1 && (strlen(s)%(q-p))==0;
        }
        else
        {
            if(p!=p1)
                q = q1;
            else
                q = q1+1;
        }
    }
    return false; //q points to end, then there's no pattern.
}

int mainRepeated()
{
    const char* s = "abab"; //"aacaaaacaa"; //"aaaa" // "abaaba" //"aab" // "a" //"abc", //"abab"
    cout << IsRepeated(s) << endl;
    return 0;
}