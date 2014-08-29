//
//  Parenthesis.cpp
//  algorithms
//
//  Created by Wentao Deng on 8/26/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <assert.h>
#include "Parenthesis.h"

const int N = 3;

class Closure
{
    int left;
    int right;
    string line;
public:
    Closure(){left=0;right=0;};
    Closure(const Closure& c){left=c.left; right=c.right; line=c.line;}
    bool InsertLeft();
    bool InsertRight();
    string Str(){return line;};
};

bool Closure::InsertLeft()
{
    if(left+1<right || left+1>N)
        return false;
    line.push_back('(');
    left++;
    return true;
}

bool Closure::InsertRight()
{
    if(left<right+1 || right+1>N)
        return false;
    line.push_back(')');
    right++;
    return true;
}

void PrintParenthesis()
{
    vector<Closure> result;
    Closure c;
    c.InsertLeft();
    result.push_back(c);
    for(int i=1; i<2*N; i++)
    {
        for(int j=0; j<result.size(); j++)
        {
            Closure c2(result[j]);
            if(result[j].InsertLeft())
            {
                if(c2.InsertRight())
                    result.push_back(c2);
            }
            else
                result[j].InsertRight();
        }
    }
    
    for(int j=0; j<result.size(); j++)
    {
        cout << result[j].Str() << endl;
    }
}

int main()
{
    PrintParenthesis();
    return 0;
}