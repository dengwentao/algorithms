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
}

int main()
{
    int A[] = {6,12,11,4,6,7,1,3,9,12,32,2,3,0,1,0};
    int size = sizeof(A)/sizeof(A[0]);
    int w = 5;
    DisplayMaxInWin(A, size, w);
    return 0;
}