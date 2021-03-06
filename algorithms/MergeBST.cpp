//
//  MergeBST.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/8/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
// Output 2 BST in sorted order.
// Space limit O(lgM+lgN).

#include <iostream>
#include <stack>
using namespace std;
#include <assert.h>
#include "MergeBST.h"

struct Node
{
    Node* pL;
    Node* pRight;
    int value;
    Node(int v){value = v; pL=pRight=0;};
};

class Bst
{
public:
    Bst(Node* pRoot) {m_pRoot = pRoot;};
    ~Bst(){m_pRoot = 0;};
    int getNext();
private:
    Node* m_pRoot;
    stack<Node*> m_Stack;
};

int Bst::getNext()
{
    while(m_pRoot)
    {
        m_Stack.push(m_pRoot);
        m_pRoot = m_pRoot->pL;
    }
    if(m_Stack.empty())
        return -1;
    Node* pRoot = m_Stack.top();
    m_pRoot = pRoot->pRight;
    m_Stack.pop();
    return pRoot->value;
}



int mainBST()
{
    Node* pRoot = new Node(11);
    pRoot->pL = new Node(7);
    pRoot->pRight = new Node(16);
    pRoot->pL->pL = new Node(3);
    pRoot->pL->pRight = new Node(8);
    pRoot->pRight->pL = new Node(13);
    pRoot->pRight->pRight = new Node(19);
    Bst bst1(pRoot);
    
    Node* pR = new Node(14);
    pR->pL = new Node(13);
    pR->pRight = new Node(16);
    pR->pL->pL = new Node(10);
    pR->pL->pL->pRight = new Node(12);
    pR->pL->pL->pRight->pL = new Node(11);
    pR->pRight->pRight = new Node(20);
    pR->pRight->pRight->pL = new Node(18);
    Bst bst2(pR);
    
    int v1 = bst1.getNext();
    int v2 = bst2.getNext();
    while(true)
    {
        if(v1>=0  && v2>=0)
        {
            if(v1 < v2)
            {
                cout << v1 << endl;
                v1 = bst1.getNext();
            }
            else
            {
                cout << v2 << endl;
                v2 = bst2.getNext();
            }
        }
        else
        {
            while(v1>0)
            {
                cout << v1 << endl;
                v1 = bst1.getNext();
            }
            while(v2>0)
            {
                cout << v2 << endl;
                v2 = bst2.getNext();
            }
    
            break;
        }

    }
    
    return 0;
}
