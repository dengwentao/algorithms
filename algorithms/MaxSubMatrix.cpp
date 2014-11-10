//
//  MaxSubMatrix.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/3/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//


#include <iostream>
#include <climits>
#include <stack>
using namespace std;
#include <assert.h>


/////////////////////////
//有一个 m x n 的矩阵，矩阵的元素可正可负。请找出该矩阵的一个子矩阵（方块），使得其所有元素之和在所有子矩阵中最大
//////////////////////////

const int R = 6;
const int C = 6;
int M[R][C] = { {-1, -16, -15, -4, -9, -10},
                {-11,-6, -25, -12, -1,-10},
                {-2, -6, -59, -14, -2, -11},
                {-4, -8,  -15, -24,-9, -18},
                {-1,-9,   -5, -4,  19,-3},
                {0, -26,  -9, 34,  -9, 11}};


int BUF[R][C][R];
void initBuf()
{
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            for(int k=0; k<R; k++)
                BUF[i][j][k] = INT_MIN;
}

//For all rectangles starting from (i, j) with height r-i+1 (i.e., r is right-bottom row index)
int SS(int i, int j, int r)
{
    if(j>=C || i>=R || i<0 || j<0)
        return 0;
    if(BUF[i][j][r]!=INT_MIN)
        return BUF[i][j][r];
    int sum = 0;
    for(int x=i; x<=r; x++)
        sum += M[x][j];
    BUF[i][j][r] = sum + SS(i, j+1, r);
    cout << "i=" << i << " j=" << j << " r=" << r << " sum=" << BUF[i][j][r] << endl;
    return BUF[i][j][r];
}



//Find out the the max sum of rectangles inside of the sub-matrix whose left-upper corner is (i, j).
int SS(int i, int j)
{
    assert(i>=0&&i<R&&j>=0&&j<C);
    int max = 0;
    for(int r=i; r<R; r++)
        if(max < SS(i,j,r))
            max = SS(i,j,r);
    return max;
}

//Find out the the max sum of rectangles inside of the given matrix
int MaxSum()
{
    initBuf();
        
    int max = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(max < SS(i, j))
                max = SS(i, j);
    return max;
}


//////////////////////////////////////
//有一个 m x n 的矩阵，元素为 0 或 1。一个子矩阵，如果它所有的元素都是 0， 或者都是 1，则称其为一个 0-聚类 或 1-聚类，
//统称聚类(Cluster)。请找出最大的聚类（元素最多的聚类）. For simplicity, find 1-cluster only.
//////////////////////////////////////
const int ROW = 6;
const int COL = 6;
int Bits[ROW][COL] =
  { {0, 1, 0, 1, 1, 1},
    {0, 1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0, 1}};


int MAP[ROW][COL][ROW];
void initMap()
{
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            for(int k=0; k<ROW; k++)
                MAP[i][j][k] = INT_MIN;
}

int CC(int i, int j, int r)
{
    if(j>=COL || i>=ROW || i<0 || j<0)
        return 0;
    if(MAP[i][j][r]!=INT_MIN)
        return MAP[i][j][r];
    bool all1 = true;
    for(int x=i; x<=r; x++)
        if(!Bits[x][j])
        {
            all1 = false;
            break;
        }
    //When col j, row i to r has a 0, CC(i,j,r) has to be cleared to 0 because this rectangle is not a cluster.
    MAP[i][j][r] = all1 ? (r-i+1+CC(i, j+1, r)) : 0;
    cout << "i=" << i << " j=" << j << " r=" << r << " count=" << MAP[i][j][r] << endl;
    return MAP[i][j][r];
}

int CC(int i, int j)
{
    assert(i>=0&&i<ROW&&j>=0&&j<COL);
    int max = 0;
    for(int r=i; r<ROW; r++)
        if(max < CC(i,j,r))
            max = CC(i,j,r);
    return max;
}

int MaxCount()
{
    initMap();
    int max = 0;
    for(int i=0; i< ROW; i++)
        for(int j=0; j<COL; j++)
            if(max < CC(i, j))
                max = CC(i, j);
    return max;
}

///////// Solution II ////////////
//Find largest 1's with histogram

int MaxRect(int T[], int size);

// r is row number, bar[] is bar height of each col for row r
int maxCnt(int r, int bar[])
{
    for(int i=0; i<COL; i++)
        bar[i] = (Bits[r][i] ? bar[i]+1 : 0);
    
    for(int i=0; i<COL+1; i++)
        cout << bar[i] << ' ';
    cout << endl;
    return MaxRect(bar, COL+1);
}

int maxCnt()
{
    //bar heights
    int bar[COL+1];
    memset(bar, 0, sizeof(bar));
    bar[COL] = 0;
    
    int m = 0;
    for(int i=0; i<ROW; i++)
    {
        int rc = maxCnt(i, bar);
        cout << i << ' ' << rc << endl;
        if(m<rc)
            m = rc;
    }
    return m;
}


//////////////////////////////////////
//有一个有 n 个项的统计直方图，假定所有的直方条 (bar) 的宽度一样。在所有边与 x 轴 和 y 轴平行的长方形中，求该被该直方图包含的面积最大的长方形
//////////////////////////////////////
struct record{
    int index; //index of current bar
    int v;  //heigh of current bar
    int ls; //left side area
    record(int i, int s, int vv){index=i;ls=s;v=vv;};
};

int MaxRect(int T[], int size)
{
    stack<record> s;
    s.push(record(-1,-1,-1)); // as boundary
    
    int max = 0;
    for(int i=0; i<size; i++)
    {
        if(T[i]>s.top().v)
            s.push(record(i, T[i], T[i]));
        else
        {
            record& top = s.top();
            while(T[i]<=top.v) //since bottom elem is (-1,-1,-1), stack won't be empty
            {
                int area = top.v*(i-top.index-1) + top.ls; //right+left
                if(max<area)
                    max = area;
                s.pop();
                top = s.top();
            }
            int l = (i-top.index)*T[i];
            s.push(record(i, l, T[i]));
        }
    }
    return max;
}

//////////////////////////////////////
//Find sub-array with max sum
//////////////////////////////////////
int MaxSumSubArray()
{
    int A[] = {1, -3, 4, 6, -10, 1, 3, 5, -2, 4};
    int size = sizeof(A)/sizeof(A[0]);
    int max = 0;
    int M = 0;
    for(int i=0; i<size; i++)
    {
        if(M<=0)
            M = A[i];
        else
            M += A[i];
        if(M>max)
            max = M;
    }
    return max;
}

int mainRect()
{
    //cout << MaxSum() << endl;
    //cout << MaxCount() << endl;
    //cout << MaxSumSubArray() << endl;
    //int T[] = {6,7,8,6,2,7,8,9,0};
    //int T[] = {0, 1, 0, 1, 1, 1, 0  };
    //int sizeT = sizeof(T)/sizeof(T[0]);
    //cout << MaxRect(T, sizeT) << endl;
    cout << maxCnt() << endl;
    return 0;
}
