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
    Node* pLeft;
    Node* pRight;
    int value;
    Node(int v){value = v; pLeft=pRight=0;};
};

//Find the tree here
// http://leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
Node* initTree()
{
    Node* pRoot = new Node(28);
    pRoot->pLeft = new Node(4);
    pRoot->pRight = new Node(69);
    pRoot->pLeft->pRight = new Node(8);
    pRoot->pRight->pLeft = new Node(56);
    pRoot->pLeft->pRight->pLeft = new Node(7);
    pRoot->pLeft->pRight->pRight = new Node(12);
    pRoot->pRight->pLeft->pLeft = new Node(34);
    pRoot->pRight->pLeft->pRight = new Node(27);
    pRoot->pLeft->pRight->pLeft->pLeft = new Node(5);
    pRoot->pLeft->pRight->pRight->pRight = new Node(13);
    pRoot->pRight->pLeft->pLeft->pLeft = new Node(2);
    pRoot->pRight->pLeft->pRight->pLeft = new Node(3);
    pRoot->pRight->pLeft->pRight->pRight = new Node(39);
    pRoot->pLeft->pRight->pLeft->pLeft->pRight = new Node(6);
    pRoot->pLeft->pRight->pRight->pRight->pLeft = new Node(11);
    pRoot->pRight->pLeft->pLeft->pLeft->pLeft = new Node(10);
    pRoot->pRight->pLeft->pRight->pLeft->pLeft = new Node(9);
    
    return pRoot;
}

void PreTrav(Node* pRoot, bool leftEdge)
{
    assert(pRoot);
    if(leftEdge || !pRoot->pLeft && !pRoot->pRight)
        cout << pRoot->value << ' ';
    if(pRoot->pLeft)
        PreTrav(pRoot->pLeft, leftEdge);
    if(pRoot->pRight)
        PreTrav(pRoot->pRight, leftEdge && !pRoot->pLeft);
}

void PostTrav(Node* pRoot, bool rightEdge)
{
    assert(pRoot);
    if(pRoot->pLeft)
        PostTrav(pRoot->pLeft, rightEdge && !pRoot->pRight);
    if(pRoot->pRight)
        PostTrav(pRoot->pRight, rightEdge);
    if(rightEdge || !pRoot->pLeft && !pRoot->pRight)
        cout << pRoot->value << ' ';
}

int mainEdge()
{
    Node* pRoot = initTree();
    cout << pRoot->value << ' ';
    if(pRoot->pLeft)
        PreTrav(pRoot->pLeft, true);
    if(pRoot->pRight)
        PostTrav(pRoot->pRight, true);
    return 0;
}