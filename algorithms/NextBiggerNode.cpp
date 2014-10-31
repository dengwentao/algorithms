//
//  NextBiggerNode.cpp
//  algorithms
//
//  Created by Wentao Deng on 10/30/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <climits>
#include <iostream>
#include <stack>
using namespace std;
#include <assert.h>

struct Node
{
    Node* pLeft;
    Node* pRight;
    int value;
    Node(int v){value = v; pLeft=pRight=0;};
};

class Bst
{
public:
    Bst(Node* pRoot) {m_pRoot = pRoot;};
    ~Bst(){m_pRoot = 0;};
    int NextBigger(int v);
private:
    int Trav(Node* pNode, int v, int min, int max);
    int InOrderFirst(Node* pNode);
    Node* m_pRoot;
};

//Given a value, find the value that is next bigger.
int Bst::NextBigger(int v)
{
    return Trav(m_pRoot, v, INT_MIN, INT_MAX);
}

int Bst::Trav(Node* pNode, int v, int min, int max)
{
    if(pNode==0)
        return max;
    if(pNode->value < v)
        return Trav(pNode->pRight, v, pNode->value, max);
    else if(pNode->value > v)
        return Trav(pNode->pLeft, v, min, pNode->value);
    else
    {
        if(pNode->pRight==0)
            return max;
        else
            //in order first of this sub-tree
            return InOrderFirst(pNode->pRight);
    }
}

int Bst::InOrderFirst(Node* pNode)
{
    if(pNode->pLeft==0 )
        return pNode->value;
    else
        return InOrderFirst(pNode->pLeft);
}

int mainNextBig()
{
    Node* pRoot = new Node(11);
    pRoot->pLeft = new Node(7);
    pRoot->pRight = new Node(16);
    pRoot->pLeft->pLeft = new Node(3);
    pRoot->pLeft->pRight = new Node(8);
    pRoot->pRight->pLeft = new Node(13);
    pRoot->pRight->pRight = new Node(19);
    Bst bst(pRoot);
    cout << bst.NextBigger(9)<< endl;
    return 0;
}