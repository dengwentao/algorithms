//
//  HighestFreqSubStr.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/13/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

// Given input string, find sub string with highest frequency.
// This substring should have length in [K, L] and count of distinct chars no greater than M.

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
#include <assert.h>


#include <iostream>
using namespace std;

//stat distinct char from index 0 with length len.
unordered_map<char, int> stats(const string& input, int len)
{
    unordered_map<char, int> res;
    for(int i=0; i<len; i++)
        res[input[i]] += 1;
    return res;
}

int mainHiFreq() {
    int K=2, L=3, M=3; //substring length in [K, L] and distinct chars count no larger than M.
    string input = "abcabcab";
    
    if(input.length()<K || K<0 || L<0  || L<K || M<=0)
        return 0;
    
    // stat the freqency of substrings
    unordered_map<string, int> maps;
    //stat the frequency of chars in a substring.
    //at the beginning, stat substring from 0 with length k-1.
    unordered_map<char, int> init = stats(input, K-1);
    for(int len=K; len<=L; len++)
    {
        //each time length increment, input the new char.
        init[input[len-1]] += 1;
        //make another copy for sliding window.
        unordered_map<char, int> freq = init;
        if(freq.size() <= M)
            maps[input.substr(0, len)] += 1;
        for(int i=1; i<=int(input.length())-len; i++)
        {
            //sliding window by moving right 1
            freq[input[i-1]] -= 1;
            if(freq[input[i-1]]==0)
                freq.erase(input[i-1]);
            freq[input[i+len-1]] += 1;
            if(freq.size() > M)
                continue;
            string sub = input.substr(i, len);
            cout << sub << endl;
            maps[sub] += 1;
        }
    }
    
    int max = 0;
    for(auto it=maps.begin(); it!=maps.end(); ++it)
    {
        if(it->second > max)
            max = it->second;
    }
    cout << max << endl;
    
    return 0;
}