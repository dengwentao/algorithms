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
    Node* pLeft;
    Node* pRight;
    int value;
    Node* pNext;
    Node(int v){value = v; pLeft=pRight=0;};
};

//Find the tree here
// http://leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
Node* initTreeNodes()
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

void PopulateNext(Node* pRoot, int level, Node* head[])
{
    assert(pRoot);
    pRoot->pNext = head[level];
    head[level] = pRoot;
    if(pRoot->pRight)
        PopulateNext(pRoot->pRight, level+1, head);
    if(pRoot->pLeft)
        PopulateNext(pRoot->pLeft, level+1, head);
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