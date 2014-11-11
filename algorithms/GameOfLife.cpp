//
//  GameOfLife.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/10/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

//http://en.wikipedia.org/wiki/Conway's_Game_of_Life
//Given a grid of cells each of which is in one of two possible states, alive or dead.
//Every cell interacts with its eight neighbours.
//At each step in time, the following transitions occur:
//1) Any live cell with fewer than two live neighbours dies, as if caused by under-population.
//2) Any live cell with two or three live neighbours lives on to the next generation.
//3) Any live cell with more than three live neighbours dies, as if by overcrowding.
//4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
//The initial pattern constitutes the seed of the system.

#include <iostream>
using namespace std;
#include <assert.h>
#include "rlutil.h"

class GameOfLife
{
    int row;
    int col;
    bool** CurrentGrid;
    bool** ResultGrid;
public:
    GameOfLife(int r, int c);
    ~GameOfLife();
    void Init();
    void Step();
    void Display();
protected:
    int neighbors(int i, int j);
    bool cell(int i, int j);
};


GameOfLife::GameOfLife(int r, int c): row(r), col(c)
{
    assert(row>0 && col>0);
    CurrentGrid = new bool* [row];
    for(int i=0; i<row; i++)
    {
        CurrentGrid[i] = new bool[col];
        memset(CurrentGrid[i], false, col);
    }
    ResultGrid = new bool* [row];
    for(int i=0; i<row; i++)
    {
        ResultGrid[i] = new bool[col];
        memset(ResultGrid[i], false, col);
    }
    rlutil::setColor(10);
}

GameOfLife::~GameOfLife()
{
    for(int i=0; i<row; i++)
    {
        delete[] CurrentGrid[i];
        delete[] ResultGrid[i];
    }
    delete[] CurrentGrid;
    delete[] ResultGrid;
}

void GameOfLife::Display()
{
    rlutil::locate(0, 0);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout << (CurrentGrid[i][j] ? " *" : " .");
        cout << endl;
    }
    rlutil::msleep(1000);
}

//Seed of life
void GameOfLife::Init()
{
    //Seed Blinker
    //CurrentGrid[2][1] = true;
    //CurrentGrid[2][2] = true;
    //CurrentGrid[2][3] = true;
    
    //Seed Glider
    CurrentGrid[1][2] = true;
    CurrentGrid[2][3] = true;
    CurrentGrid[3][3] = true;
    CurrentGrid[3][2] = true;
    CurrentGrid[3][1] = true;
    
    //Seed Beacon
    //CurrentGrid[1][1] = true;
    //CurrentGrid[1][2] = true;
    //CurrentGrid[2][1] = true;
    //CurrentGrid[4][4] = true;
    //CurrentGrid[4][3] = true;
    //CurrentGrid[3][4] = true;
}

//Generate grid for next step. The result is then stored back to CurrentGrid.
void GameOfLife::Step()
{
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
        {
            int count = neighbors(i, j);
            if(CurrentGrid[i][j])
            {
                if(count<2)
                    ResultGrid[i][j] = false;
                else if(count<4)
                    ResultGrid[i][j] = true;
                else
                    ResultGrid[i][j] = false;
            }
            else
            {
                if(count==3)
                    ResultGrid[i][j] = true;
            }
        }
    bool** tmp = CurrentGrid;
    CurrentGrid = ResultGrid;
    ResultGrid = tmp;
}

//check if cell[i,j] is alive or dead.
//This is mainly to handle boundaries. Cell outside of boundries is dead.
bool GameOfLife::cell(int i, int j)
{
    if(i<0||j<0||i>=row||j>=col)
        return false;
    return CurrentGrid[i][j];
}

//count number of live neighbors of cell [i,j].
int GameOfLife::neighbors(int i, int j)
{
    int count=0;
    for(int r=i-1; r<=i+1; r++)
        for(int c=j-1; c<=j+1; c++)
        {
            if(cell(r,c))
                count++;
        }
    if(cell(i,j))
        count--;
    return count;
}

int main()
{
    GameOfLife gol(30, 30);
    gol.Init();
    gol.Display();
    for(int i=0; i<100; i++)
    {
        gol.Step();
        gol.Display();
    }
    return 0;
}