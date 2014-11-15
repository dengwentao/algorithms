//
//  MaxPointsOnLine.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/14/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;
#include <assert.h>

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
    float slop(const Point& p1, const Point& p2)
    {
        if(p2.x==p1.x && p2.y==p1.y)
            return INT_MIN;
        if(p2.x==p1.x)
            return INT_MAX;
        return float(p2.y-p1.y)/(p2.x-p1.x);
    };
public:
    //empty, single, dup?
    int maxPoints(vector<Point> &points) {
        if(points.size()<=2)
            return points.size();
        int max = 0;
        for(int i=0; i<points.size()-1; i++)
        {
            unordered_map<float, int> slops;
            int dups = 0; //count how many dups as the start point.
            for(int j=i+1; j<points.size(); j++)
            {
                float slp = slop(points[i], points[j]);
                if(slp==INT_MIN) // dup point with the start point
                    dups++;
                else
                    slops[slp] += 1;
            }
            int m = 0;
            if(slops.size()>0)
            {
                vector<int> counts;
                for(auto each: slops)
                    counts.push_back(each.second);
                //points with same slop, dups of the start point, and the start point itself.
                m = 1 + dups + *max_element(counts.begin(), counts.end());
            }
            else
                m = 1 + dups;
            if(max < m)
                max = m;
        }
        return max; //add the start point
    }
};

int mainPoints()
{
    Point p[] = {{0,0}, {1,1}, {1,1}};
    vector<Point> points(p, p+sizeof(p)/sizeof(p[0]));
    Solution sol;
    cout << sol.maxPoints(points) << endl;
    return 0;
}

