/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.29%)
 * Total Accepted:    535.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;

        if(!l1)
            return l2;
        
        if(!l2)
            return l1;

        ListNode* head;

        if(l1->val >= l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else
        {
            head = l1;
            l1 = l1->next;
        }

        ListNode* res = head;

        while(l1 && l2)
        {
            if(l1->val >= l2->val)
            {
                head->next = l2;
                l2 = l2->next;
            }
            else
            {
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }

        if (l1)
            head->next = l1;
        if (l2)
            head->next = l2;
        
        return res;
    }
};

