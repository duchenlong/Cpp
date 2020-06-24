/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* curLe = l1;
        ListNode* curRi = l2;
        ListNode* head = new ListNode(0);
        ListNode* phead = head;

        while(curLe && curRi)
        {
            if(curLe->val < curRi->val)
            {
                phead->next = curLe;
                curLe = curLe->next;
            }
            else
            {
                phead->next = curRi;
                curRi = curRi->next;
            }
            phead = phead->next;
        }

        if(curLe == nullptr)
            phead->next = curRi;
        if(curRi == nullptr)
            phead->next = curLe;
        ListNode* ret = head->next;
        delete head;
        return ret;
    }


    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }

        //l1->val > l2->val
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
};
