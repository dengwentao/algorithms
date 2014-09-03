//
//  Pegs.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/2/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/*
 http://leetcode.com/2011/01/peg-game-problem-analysis.html
 Pegs arranged below. x is peg while . is vacant, and ^ marks target position.
 Drop a ball on any peg in the top row, and it will finally drop down to bottom.
 Where should we drop it so that we have max probability to see the ball hit target pos?
 x.x.x.x.x
  x...x.x
 x...x.x.x
  x.x...x
 x.x.x.x.x
  ^
 */

#include <iostream>
using namespace std;
#include <assert.h>
#include "Pegs.h"


const int R=5; // R should be odd
const int C=5;
bool Array[R+1][C*2-1];
float P[R+1][C*2-1]; // to record probabilities

// init whole pegs
void initPegs()
{
    memset(Array[0], false, 2*C-1);
    for(int j=0; j<2*C-1; j+=2)
        Array[0][j] = true;
    for(int i=2; i<R; i+=2)
        memcpy(Array[i], Array[0], 2*C-1);
    
    memset(Array[1], false, 2*C-1);
    for(int j=1; j<2*C-1; j+=2)
        Array[1][j] = true;
    for(int i=3; i<R; i+=2)
        memcpy(Array[i], Array[1], 2*C-1);
    
    // last row as result
    memset(Array[R], true, 2*C-1);
}

// set missing pegs.
// columns in 2 sides cannot have missing pegs
void setMissing()
{
    Array[1][3] = false;
    Array[2][2] = false;
    Array[3][5] = false;
}

// To reset P to 0 each time we put a ball.
void resetP()
{
    for(int i=0; i<R+1; i++)
        for(int j=0; j<2*C-1; j++)
            P[i][j] = 0.0;
}

//When ball is at position Array[i][j], let it bounce down to next peg and set P.
//left is true means bounce to left, else right.
void bounce(int i, int j, bool left)
{
    assert(i>=0 && i<R && j>=0 && j<2*C-1);
    float p = 0.5;
    if(j==0)
    {
        if(left)
            return;
        else
            p = 1.0;
    }
    if(j==2*C-2)
    {
        if(left)
            p = 1.0;
        else
            return;
    }

    // Moving down unless there's a peg.
    // Note that row/col at the 4 edges have no missing peg.
    int step = (left ? -1 : 1);
    while(!Array[i+abs(step)][j+step])
    {
        if(left)
            step--;
        else
            step++;
    }
    P[i+abs(step)][j+step] += p * P[i][j];
}

//col stands for the column of pegs starting from 0, and is actually col*2 in matrix.
//target is the col in the matrix.
float putBall(int col, int target)
{
    resetP();
    P[0][col*2] = 1.0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<2*C-1; j++)
        {
            if(P[i][j]>0)
            {
                //Either go left or right.
                bounce(i, j, true);
                bounce(i, j, false);
            }
        }
    }
    return P[R][target];
}

int main()
{
    initPegs();
    setMissing();
    for(int i=0; i<R+1; i++)
    {
        for(int j=0; j<2*C-1; j++)
            cout << Array[i][j] << ' ';
        cout << endl;
    }
    
    float max=0.0;
    int col=0;
    // actually we don't need to try each column, but let's just save some time.
    for(int i=0; i<C; i++)
    {
        float p = putBall(i, 1);
        if(p>max)
        {
            max = p;
            col = i;
        }
    }
    cout << "Input from column " << col << " with max probability " << max << endl;
    
}