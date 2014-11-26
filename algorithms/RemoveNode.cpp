//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//Remove a node from the BST when given its value. There's no dupicate.

#include <iostream>
using namespace std;
#include <assert.h>

struct Nodex
{
    int v;
    Nodex* pR;
    Nodex* pL;
    Nodex(int val){v=val;pR=pL=0;};
    Nodex(const Nodex&)=default;
    Nodex& operator=(const Nodex&)=default;
};

//Find right most node. Upon return, root point to that node.
void FindRightMostNode(Nodex*& root)
{
    if(root==0)
        return;
    if(0==root->pR)
        return;
    else
    {
        root = root->pR;
        FindRightMostNode(root);
    }
}

//Remove a node from BST whose value is v. It's possible the root node is changed.
//return true is the node is found.
bool RemoveBstValue(Nodex*& root, int v)
{
    if(root==0)
        return false;
    if(root->v < v)
        return RemoveBstValue(root->pR, v);
    else if(root->v > v)
        return RemoveBstValue(root->pL, v);
    else
    {
        //we found the node
        cout << root->v << endl;
        Nodex* pNode = root;
        if(!root->pL)
        {
            root = root->pR;
        }
        else
        {
            //Find right most node of left tree so that we can insert right tree there.
            Nodex* pInsertPoint = root->pL;
            FindRightMostNode(pInsertPoint);
            pInsertPoint->pR = root->pR;
            root = root->pL;
        }
        delete pNode;
        return true;
    }
}


Nodex* CreateBST()
{
    Nodex* pRoot = new Nodex(15);
    pRoot->pL = new Nodex(7);
    pRoot->pR = new Nodex(20);
    pRoot->pL->pL = new Nodex(6);
    pRoot->pL->pR = new Nodex(11);
    pRoot->pL->pR->pL = new Nodex(9);
    pRoot->pL->pR->pL->pL = new Nodex(8);
    pRoot->pL->pR->pL->pR = new Nodex(10);
    pRoot->pL->pR->pR = new Nodex(14);
    pRoot->pL->pR->pR->pL = new Nodex(13);
    
    return pRoot;
}

void PrintTree(Nodex* pRoot)
{
    if(!pRoot)
        return;
    PrintTree(pRoot->pL);
    cout << pRoot->v << ' ';
    PrintTree(pRoot->pR);
}

int mainRemove()
{
    Nodex* root = CreateBST();
    PrintTree(root);
    cout << endl;
    if(!RemoveBstValue(root, 15))
        cout << "Not found." << endl;
    PrintTree(root);
    cout << endl;
    return 0;
}