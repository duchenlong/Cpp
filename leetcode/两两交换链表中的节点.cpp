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
    ListNode* swapPairs1(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* ret = new ListNode(-1);
        ret->next = head;
        ListNode* pre = ret;
        ListNode* cur = head;
        ListNode* curNext = cur->next;

        while(curNext != nullptr) {
            ListNode* next = curNext->next;

            pre->next = curNext;
            curNext->next = cur;

            pre = cur;
            pre->next = nullptr;
            cur = next;
            if(cur == nullptr) break;
            curNext = cur->next;
        }

        if(cur != nullptr) pre->next = cur,cur->next = nullptr;
        
        ListNode* ans = ret->next;
        delete ret;

        return ans;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};


给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

?

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
