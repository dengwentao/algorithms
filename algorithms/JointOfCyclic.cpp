//
//  test.cpp
//  algorithms
//
//  Created by Wentao Deng on 9/19/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    //head is null, cycle points to head, single node cycle, no cycle.
    //if cyclic has only 1 node, return it as the joint.
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* p = head;
        ListNode* q = head;
        
        //run in circle until they meet
        do
        {
            p = p->next;
            q = q->next;
            if(!q)
                return NULL;
            q = q->next;
        }while(p!=q && p!=0 && q!=0);
        
        //no cyclic
        if(p==0 || q==0)
            return NULL;
        
        //count cyclic length
        int cycle = 0;
        do
        {
            p = p->next;
            q = q->next;
            q = q->next;
            cycle++;
        }while(p!=q);
        
        p = head;
        q = head;
        for(int i=0; i<cycle; i++)
        {
            p = p->next;
        }
        while(p!=q)
        {
            p = p->next;
            q = q->next;
        }
        
        return p;
    }
};

int mainJoint()
{
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = list;
    Solution sol;
    ListNode* pJoint = sol.detectCycle(list);
    if(pJoint)
        cout << pJoint->val << endl;
    else
        cout << "no cyclic" << endl;
    return 0;
}