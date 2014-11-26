//
//  BiTreeEdges.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/15/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Print all edge nodes of a binary tree anti-clockwise.


#include <iostream>
#include <map>
using namespace std;
#include <assert.h>
#include "BiTreeEdges.h"


struct Node
{
    Node* pL;
    Node* pRight;
    int value;
    Node(int v){value = v; pL=pRight=0;};
};

//Find the tree here
// http://leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
Node* initTree()
{
    Node* pRoot = new Node(28);
    pRoot->pL = new Node(4);
    pRoot->pRight = new Node(69);
    pRoot->pL->pRight = new Node(8);
    pRoot->pRight->pL = new Node(56);
    pRoot->pL->pRight->pL = new Node(7);
    pRoot->pL->pRight->pRight = new Node(12);
    pRoot->pRight->pL->pL = new Node(34);
    pRoot->pRight->pL->pRight = new Node(27);
    pRoot->pL->pRight->pL->pL = new Node(5);
    pRoot->pL->pRight->pRight->pRight = new Node(13);
    pRoot->pRight->pL->pL->pL = new Node(2);
    pRoot->pRight->pL->pRight->pL = new Node(3);
    pRoot->pRight->pL->pRight->pRight = new Node(39);
    pRoot->pL->pRight->pL->pL->pRight = new Node(6);
    pRoot->pL->pRight->pRight->pRight->pL = new Node(11);
    pRoot->pRight->pL->pL->pL->pL = new Node(10);
    pRoot->pRight->pL->pRight->pL->pL = new Node(9);
    
    return pRoot;
}

void PreTrav(Node* pRoot, bool leftEdge)
{
    assert(pRoot);
    if(leftEdge || !pRoot->pL && !pRoot->pRight)
        cout << pRoot->value << ' ';
    if(pRoot->pL)
        PreTrav(pRoot->pL, leftEdge);
    if(pRoot->pRight)
        PreTrav(pRoot->pRight, leftEdge && !pRoot->pL);
}

void PostTrav(Node* pRoot, bool rightEdge)
{
    assert(pRoot);
    if(pRoot->pL)
        PostTrav(pRoot->pL, rightEdge && !pRoot->pRight);
    if(pRoot->pRight)
        PostTrav(pRoot->pRight, rightEdge);
    if(rightEdge || !pRoot->pL && !pRoot->pRight)
        cout << pRoot->value << ' ';
}

int mainEdge()
{
    Node* pRoot = initTree();
    cout << pRoot->value << ' ';
    if(pRoot->pL)
        PreTrav(pRoot->pL, true);
    if(pRoot->pRight)
        PostTrav(pRoot->pRight, true);
    return 0;
}