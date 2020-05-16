//给你一个链表，每?k?个节点一组进行翻转，请你返回翻转后的链表。

//k?是一个正整数，它的值小于或等于链表的长度。

//如果节点总数不是?k?的整数倍，那么请将最后剩余的节点保持原有顺序。

//?

//示例：

//给你这个链表：1->2->3->4->5

//当?k?= 2 时，应当返回: 2->1->4->3->5

//当?k?= 3 时，应当返回: 3->2->1->4->5

//?

//说明：

//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 0 || k == 1) return head;

        ListNode* ret = new ListNode;
        ListNode* retNext = ret;
        ret->next = head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(slow)
        {
            int count = k - 1;
            while(count)
            {
                if(fast->next) fast=fast->next;
                else break;
                count--;
            }
            if(count) break;

            Reverse(retNext,slow,fast,k);
            
            retNext = slow;
            slow = slow->next;
            fast = slow;
        }
        head = ret->next;
        delete ret;
        return head;
    }

    void Reverse(ListNode* shead, ListNode* begin,ListNode* end,int k)
    {
        ListNode* endNext = end->next;
        ListNode* cur = begin->next;
        ListNode* b = begin;
        for(int i = 1; i < k; i++)
        {
            ListNode* _next = cur->next;
            cur->next = b;
            b = cur;
            cur = _next;
        }
        shead->next = end;
        begin->next = endNext;
    }
};
