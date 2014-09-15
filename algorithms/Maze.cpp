//
//  Maze.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/15/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//  A robot is located at the top-left corner of a m x n grid (marked ‘Start’ in the diagram below). The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below). How many possible unique paths are there?

#include <iostream>
#include <map>
using namespace std;
#include <assert.h>
#include "Maze.h"

const int M = 3;
const int N = 7;
int Maze[M][N];

void initMaze()
{
    for(int i=0; i<M; i++)
        memset(Maze[i], -1, N*sizeof(Maze[0]));
}

int Way(int row, int col)
{
    assert(row>=0 && col>=0);
    if(row>=M || col>=N)
        return 0;
    if(row==M-1 && col==N-1)
        return 1;
    if(Maze[row][col]!=-1)
        return Maze[row][col];
    Maze[row][col] = Way(row+1, col) + Way(row, col+1);
    return Maze[row][col];
}

int main()
{
    initMaze();
    cout << Way(0, 0) << endl;
    return 0;
}
