//
//  SlideWinMax.cpp
//  algorithms
//
//  Created by Wentao Deng on 10/31/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <climits>
#include <iostream>
#include <deque>
using namespace std;
#include <assert.h>

void PrintDeque(deque<int>& q, int A[])
{
    for(deque<int>::const_iterator it=q.begin(); it!=q.end(); ++it)
        cout << A[*it] << ' ';
    cout << endl;
}

//Assuming that w>1. If w==1, just output all.
void DisplayMaxInWin(int A[], int size, int w)
{
    assert(A&&size>=w&&w>1);
    deque<int> q;  // to hold index
    int pos = 1;
    q.push_back(0);
    while(pos!=size)
    {
        if(pos-q.front()>=w)
        {
            //if out of the window, left side moves forward
            q.pop_front();
        }
        //now we are in the same window
        if(A[pos]>A[q.front()])
        {
            q.clear();
            q.push_front(pos);
        }
        else
        {
            if(q.size()>1 && A[pos]>A[q.back()])
                q.pop_back();
            q.push_back(pos);
        }
        
        if(pos>=w-1)
            cout << A[q.front()] << ' ';
        pos++;
        
        //PrintDeque(q, A);
    }
    cout << endl;
}


void DisplayMaxInWin_v2(int A[], int n, int w) {
    deque<int> Q;
    for (int i = 0; i < w; i++) {
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    
    for (int i = w; i < n; i++) {
        cout << A[Q.front()] << ' ';
        while (!Q.empty() && A[i] >= A[Q.back()])
            Q.pop_back();
        while (!Q.empty() && Q.front() <= i-w)
            Q.pop_front();
        Q.push_back(i);
    }
    
    cout << A[Q.front()] << endl;
}

int mainSlidWin()
{
    int A[] = {6,12,11,4,6,7,1,3,9,12,32,2,3,0,1,0};
    int size = sizeof(A)/sizeof(A[0]);
    int w = 5;
    DisplayMaxInWin(A, size, w);
    DisplayMaxInWin_v2(A, size, w);
    return 0;
}