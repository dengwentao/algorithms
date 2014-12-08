//
//  LinkedListBasics.cpp
//  algorithms
//
//  Created by Wentao Deng on 12/2/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* CreateList2()
{
    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(3);
    pHead->next->next = new ListNode(5);
    pHead->next->next->next = new ListNode(7);
    pHead->next->next->next->next = new ListNode(10);
    return pHead;
}

void PrintList2(ListNode* pHead)
{
    if(!pHead)
        return;
    cout << pHead->val << ' ';
    PrintList2(pHead->next);
}

int Length2(ListNode* pHead)
{
    int l = 0;
    while(pHead)
    {
        pHead = pHead->next;
        l++;
    }
    return l;
}


// input list head, and return new list head.
ListNode* Delete(ListNode* head, int x)
{
        if(!head)
                return 0;
        if(head->val==x)
                return Delete(head->next, x);
        else
        {
            head->next = Delete(head->next, x);
            return head;
        }
}

// input list head and return new list head after inserting x.
ListNode* Insert(ListNode*& head, int x)
{
       if(!head || head->val > x)
        {
            ListNode* p = head;
            head = new ListNode(x);
            head->next = p;
        }
        else
            head->next = Insert(head->next, x);
        return head;
}

int mainList()
{
    ListNode* list = CreateList2();
    ListNode* list1 = Insert(list, 11);
    ListNode* list2 = Insert(list, 0);
    PrintList2(list2);
    cout << endl;
    ListNode* list3 = Delete(list2, 0);
    ListNode* list4 = Delete(list3, 11);
    PrintList2(list4);
    return 0;
}
