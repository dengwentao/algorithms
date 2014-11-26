//
//  SortLinkedList.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/23/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

/**
 Sort a linked list in O(n log n) time using constant space complexity.
 */

#include <iostream>
#include <climits>
using namespace std;
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* CreateList()
{
    ListNode* pHead = new ListNode(10);
    pHead->next = new ListNode(8);
    pHead->next->next = new ListNode(3);
    pHead->next->next->next = new ListNode(7);
    pHead->next->next->next->next = new ListNode(1);
    return pHead;
}

void PrintList(ListNode* pHead)
{
    if(!pHead)
        return;
    cout << pHead->val << ' ';
    PrintList(pHead->next);
}

int Length(ListNode* pHead)
{
    int l = 0;
    while(pHead)
    {
        pHead = pHead->next;
        l++;
    }
    return l;
}

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next)
            return head;
        int len = Length(head);
        ListNode* dummy = new ListNode(INT_MIN); //dummy head of the full list.
        dummy->next = head;
        ListNode* tail = 0; //always point to the tail of current partially sorted list.
        for(int width=1; width<len; width*=2)
        {
            //start one pass
            ListNode* p1 = dummy->next; //always points to working position of list 1
            ListNode* p2 = p1; //always points to working position of list 2
            tail = dummy;
            
            while(p2)
            {
                //Start to merge 2 partitions
                
                //Move p2 to point to head of partition 2
                p2 = p1;
                for(int i=0; i<width && p2; i++)
                    p2 = p2->next;
                
                //merge two partitions
                int width1=0, width2=0;
                while(width1<width && width2<width && p1 && p2)
                {
                    if(p1->val <= p2->val)
                    {
                        tail->next = p1;
                        p1 = p1->next;
                        width1++;
                    }
                    else
                    {
                        tail->next = p2;
                        p2 = p2->next;
                        width2++;
                    }
                    tail = tail->next;
                }
                
                //one partition may have remaining nodes, append them.
                if(width1<width && p1)
                {
                    //partition 1 has remaining nodes
                    while(p1 && width1<width)
                    {
                        tail->next = p1;
                        p1 = p1->next;
                        tail = tail->next;
                        width1++;
                    }
                }
                else
                {
                    //partition 2 has remaining nodes, or not.
                    while(p2 && width2<width)
                    {
                        tail->next = p2;
                        p2 = p2->next;
                        tail = tail->next;
                        width2++;
                    }
                }
                
                //Now that we finished merging two partitions, go to next partition. Before that, let p1 point to next partition.
                p1 = p2;
            }
            tail->next = 0; //terminate the full list as tail node may have changed.
        }
        return dummy->next;
    }
};

int mainMergeList()
{
    ListNode* pHead = CreateList();
    PrintList(pHead);
    cout << endl;
    Solution sol;
    pHead = sol.sortList(pHead);
    PrintList(pHead);
    return 0;
}