//
//  NormalizePath.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/10/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

// path normalization
// in: /asdf/./qwer/..xy/foo
// out: /asdf/foo



#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Output(vector<string>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]==".")
            v[i].clear();
        else if(v[i]==string(".."))
        {
            v[i].clear();
            int j = i-1;
            while(j>=0 && v[j].length()==0)
            {
                j--;
            }
            v[j].clear();
        }
    }
    
    string result = "";
    for(string s : v)
    {
        if(!s.empty())
            result.append("/" + s);
    }
    return result;
}

// // or ///, empty, ....
string Normalize(string input)
{
    if(input.back()!='/')
        input += '/';
    vector<string> result;
    int prev = 0;
    int cur = input.find('/', prev);
    while(cur != string::npos)
    {
        string component = input.substr(prev, cur-prev);
        result.push_back(component);
        prev = cur + 1;
        cur = input.find('/', prev);
    }
    
    
    string s = Output(result);
    if(input[0]!='/')
        s.erase(0, 1);
    return s;
}

int mainNormPath() {
    string s = Normalize("/asdf/./qwer/../../..////..xy/../../foo/./.");
    cout << s << endl;
    return 0;
}
