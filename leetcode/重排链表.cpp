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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return ;

        // 找到中点
        ListNode* slow = head;
        ListNode* pre = nullptr;
        ListNode* fast = head;
        while ( fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow 为 mid 点
        // 翻转 slow 后
        pre->next = nullptr;
        ListNode* mid = slow;
        ListNode* sNext = slow->next;
        slow->next = nullptr;
        while(sNext != nullptr) {
            ListNode* tmp = sNext->next;
            sNext->next = slow;
            slow = sNext;
            sNext = tmp;
        }

        // ListNode* t = head;
        // while(t != mid) {
        //     cout << t->val << " ";
        //     t = t->next;
        // }
        // cout << endl;

        // t = slow;
        // while(t) {
        //     cout << t->val << " ";
        //     t = t->next;
        // }

        // 插入
        pre = nullptr;
        ListNode* le = head;
        ListNode* ri = slow;
        while ( (le != nullptr) && (ri != nullptr)) {
            pre = le;
            ListNode* riNext = ri->next;
            ListNode* leNext = le->next;
            
            le->next = ri;
            ri->next = leNext;
            le = leNext;
            ri = riNext;
        }
        if(ri) pre->next->next = ri;
    }
};


给定一个单链表?L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例?1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
