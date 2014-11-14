//
//  MinStack.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/13/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <iostream>
#include <stack>
#include <climits>
using namespace std;
#include <assert.h>

class MinStack {
    stack<int> s;
public:
    MinStack()=default;
    ~MinStack()=default;
    
    //pop # first to get min, if x<=min, push #xx#, else pop min and then push x and then min#.
    void push(int x) {
        if(s.empty())
        {
            s.push(x);
            s.push(x);
            s.push(INT_MIN);
            return;
        }
        s.pop();
        int min = s.top();
        if(x<=min)
        {
            s.push(INT_MIN);
            s.push(x);
            s.push(x);
            s.push(INT_MIN);
        }
        else
        {
            s.pop();
            s.push(x);
            s.push(min);
            s.push(INT_MIN);
        }
    }
    
    //pop # and min first to pop the top and then push them back.
    void pop() {
        if(s.empty())
            return;
        s.pop();
        int min = s.top();
        s.pop();
        int top = s.top();
        s.pop();
        if(top>min)
        {
            s.push(min);
            s.push(INT_MIN);
        }
    }
    
    //pop # and min first to get top and then push them back.
    int top() {
        if(s.empty())
            return INT_MIN;
        s.pop();
        int min = s.top();
        s.pop();
        int top = s.top();
        s.push(min);
        s.push(INT_MIN);
        return top;
    }
    
    //pop # first to get min and then push it back.
    int getMin() {
        if(s.empty())
            return INT_MIN;
        s.pop();
        int min = s.top();
        s.push(INT_MIN);
        return min;
    }
};

int mainMinStack()
{
    MinStack s;
    s.push(7);
    cout << s.getMin() << endl;
    s.push(6);
    s.push(5);
    cout << s.getMin() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << s.getMin() << endl;
    return 0;
}