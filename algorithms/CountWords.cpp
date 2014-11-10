//
//  CountWords.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/2/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;
#include <assert.h>

enum state {Start, InWord, OutWord};

bool isAlpha(const char c)
{
    return (c>='a' && c<='z');
}

int count(const char* s)
{
    assert(s);
    int count = 0;
    state S = Start;
    while(*s++!=0)
    {
        switch(S)
        {
            case Start:
                if(isAlpha(*s))
                    S = InWord;
                break;
            case InWord:
                if(!isAlpha(*s))
                {
                    S = OutWord;
                    count++;
                }
                break;
            case OutWord:
                if(isAlpha(*s))
                    S = InWord;
                break;
        }
    }
    return count;
}

int mainCountWord()
{
    cout << count("Hello world!") << endl;
    cout << count("   Hello   world!  ") << endl;
    cout << count("Hello") << endl;
    cout << count("") << endl;
    cout << count("     ") << endl;
    return 0;
}
