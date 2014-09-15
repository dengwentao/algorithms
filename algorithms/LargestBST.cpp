//
//  LargestBST.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Given a binary tree, find the largest Binary Search Tree (BST), where largest means BST with largest number of nodes in it. The largest BST may or may not include all of its descendants.

#include <iostream>
#include <climits>
using namespace std;
#include <assert.h>
#include "LargestBST.h"

struct Node
{
    Node* pLeft;
    Node* pRight;
    int value;
    Node(int v){value=v; pLeft=pRight=0;};
};

// count how many nodes are in this BST (may not include all descendents)
int MAX_COUNT = 0;
int countBst(Node* pRoot, int min, int max)
{
    if(!pRoot)
        return 0;
    int count = 0;
    if(pRoot->value>=min && pRoot->value<=max)
    {
        count ++;
        count += countBst(pRoot->pLeft, min, pRoot->value);
        count += countBst(pRoot->pRight, pRoot->value, max);
        if(count>MAX_COUNT)
            MAX_COUNT = count;
    }
    else
    {
        int cnt = countBst(pRoot, INT_MIN, INT_MAX);
        if(cnt>MAX_COUNT)
            MAX_COUNT = cnt;
        cout << pRoot->value << " has count " << MAX_COUNT << endl;
    }
    return count;
}


// This is for another similar problem.
// This problem requires BST to have all its descendants.
int max_subtree_count = 0;
bool isBst(Node* pRoot, int& min, int& max, int& count)
{
    count = 0;
    if(!pRoot)
        return true;
    cout << "Visited node " << pRoot->value << endl;
    
    int lMin=0, lMax=0, rMin=0, rMax=0, lCount=0, rCount=0;
    lMin = lMax = rMin = rMax = pRoot->value;
    // we cannot use && to shortcut because largest subtree could be on either side.
    bool bLeft = isBst(pRoot->pLeft, lMin, lMax, lCount);
    bool bRight = isBst(pRoot->pRight, rMin, rMax, rCount);
    if(bLeft && bRight && pRoot->value >= lMax && pRoot->value <= rMin)
    {
        min = lMin;
        max = rMax;
        count = lCount + rCount + 1;
        if(count > max_subtree_count)
        {
            max_subtree_count = count;
            cout << pRoot->value << " has count " << max_subtree_count << endl;
        }
        return true;
    }
    else
    {
        // we don't need to go upper if this subtree is not BST.
        return false;
    }
}

int mainLargetBST()
{
    Node* pRoot = new Node(15);
    pRoot->pLeft = new Node(10);
    pRoot->pRight = new Node(20);
    pRoot->pLeft->pLeft = new Node(6);
    pRoot->pLeft->pRight = new Node(7);
    pRoot->pLeft->pRight->pLeft = new Node(2);
    pRoot->pLeft->pRight->pLeft->pLeft = new Node(0);
    pRoot->pLeft->pRight->pLeft->pRight = new Node(8);
    pRoot->pLeft->pRight->pRight = new Node(5);
    pRoot->pLeft->pRight->pRight->pLeft = new Node(3);
    
    countBst(pRoot, INT_MIN, INT_MAX);
    cout << "Root total count is " << MAX_COUNT << endl;
    
    int count = 0;
    int min=INT_MIN, max=INT_MAX;
    isBst(pRoot, min, max, count);
    
    return 0;
}