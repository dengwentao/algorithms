//
//  BiTreeNodeNext.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/2/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
using namespace std;
#include<assert.h>

struct Node
{
    Node* pL;
    Node* pRight;
    int value;
    Node* pNext;
    Node(int v){value = v; pL=pRight=0;};
};

//Find the tree here
// http://leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
Node* initTreeNodes()
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

void PopulateNext(Node* pRoot, int level, Node* head[])
{
    assert(pRoot);
    pRoot->pNext = head[level];
    head[level] = pRoot;
    if(pRoot->pRight)
        PopulateNext(pRoot->pRight, level+1, head);
    if(pRoot->pL)
        PopulateNext(pRoot->pL, level+1, head);
}

int mainBiNext()
{
    Node* pRoot = initTreeNodes();
    const int depth = 16;
    Node* head[depth];
    memset(head, 0, depth*sizeof(Node*));
    
    PopulateNext(pRoot, 0, head);
    
    for(int i=0; i<depth && head[i]!=0; i++)
    {
        Node* pNext = head[i];
        while(pNext)
        {
            cout << pNext->value << ' ';
            pNext = pNext->pNext;
        }
        cout << endl;
    }
    return 0;
}