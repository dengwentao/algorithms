//
//  Candy.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/26/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;
#include <assert.h>

class Solution {
public:
    int candy(vector<int> &ratings) {
        list<int> candies_right;
        int rate_last = INT_MIN;
        int candy_last = 0;
        for(int rate: ratings)
        {
            if(rate>rate_last)
                candy_last++;
            else
                candy_last = 1;
            candies_right.push_back(candy_last);
            rate_last = rate;
        }
        
        rate_last = INT_MIN;
        candy_last = 0;
        list<int> candies_left;
        for(auto rit=ratings.rbegin(); rit!=ratings.rend(); ++rit)
        {
            if(*rit>rate_last)
                candy_last++;
            else
                candy_last = 1;
            candies_left.push_front(candy_last);
            rate_last = *rit;
        }
        
        int sum=0;
        auto right=candies_right.begin();
        auto left=candies_left.begin();
        while(right!=candies_right.end() && left!=candies_left.end())
        {
            sum += (*left>*right ? *left : *right);
            ++left;
            ++right;
        }
        return sum;
    }
};

int main()
{
    vector<int> ratings = {83, 74, 21, 21, 32, 33, 87, 74, 65, 55, 61, 78, 21, 14, 11};
    Solution sol;
    cout << sol.candy(ratings)<< endl;
}
