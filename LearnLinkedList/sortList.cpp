// How to merge 2 sorted linked list here, i learned from this code
// How to find middle element, ek slow rkho ek fast rkho fast = fast->next->next and slow = slow->next

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;

        if(l1->val <= l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next)return head;

        ListNode *first = head, *second = head, *pre = head;

        while(second && second->next)
        {
            pre = first;
            first = first->next;
            second = second->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(first));
    }
};
