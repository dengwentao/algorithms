//
//  FixBiTree.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/7/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//
//Two elements of a binary search tree (BST) are swapped by mistake.
//Recover the tree without changing its structure.

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
#include <assert.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* CreateBST()
    {
        TreeNode* pRoot = new TreeNode(7);
        pRoot->left = new TreeNode(15);
        pRoot->right = new TreeNode(20);
        pRoot->left->left = new TreeNode(6);
        pRoot->left->right = new TreeNode(11);
        pRoot->left->right->left = new TreeNode(9);
        pRoot->left->right->left->left = new TreeNode(8);
        pRoot->left->right->left->right = new TreeNode(10);
        pRoot->left->right->right = new TreeNode(14);
        pRoot->left->right->right->left = new TreeNode(13);
        
        return pRoot;
    }
    
    void PrintTree(TreeNode* pRoot)
    {
        if(!pRoot)
            return;
        PrintTree(pRoot->left);
        cout << pRoot->val << ' ';
        PrintTree(pRoot->right);
    }
    
    TreeNode* travelSequencial(TreeNode* root, TreeNode*& prev)
    {
        if(!root)
            return 0;
        TreeNode* p1 = travelSequencial(root->left, prev);
        if(p1)
            return p1;
        if(prev->val > root->val)
            return prev;
        prev = root;
        return travelSequencial(root->right, prev);
    }
    
    TreeNode* travelReversed(TreeNode* root, TreeNode*& prev)
    {
        if(!root)
            return 0;
        TreeNode* p2 = travelReversed(root->right, prev);
        if(p2)
            return p2;
        if(prev->val < root->val)
            return prev;
        prev = root;
        return travelReversed(root->left, prev);
    }

    void recoverTree(TreeNode *root)
    {
        TreeNode* prev = new TreeNode(INT_MIN);
        TreeNode* p1 = travelSequencial(root, prev);
        prev = new TreeNode(INT_MAX);
        TreeNode* p2 = travelReversed(root, prev);
        if(p1 && p2)
        {
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
    }
};

int mainRecover()
{
    Solution sol;
    TreeNode* pRoot = sol.CreateBST();
    sol.PrintTree(pRoot);
    cout << endl;
    sol.recoverTree(pRoot);
    sol.PrintTree(pRoot);
    return 0;
}