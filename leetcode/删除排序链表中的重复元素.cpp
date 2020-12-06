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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode(-1);
        ListNode* cur = ret;

        ListNode* t = head;
        while(t) {
            ListNode* tNext = t->next;
            while(tNext && tNext->val == t->val) tNext = tNext->next;
            t->next = nullptr;
            cur->next = t;
            cur = cur->next;
            t = tNext;
        }
        return ret->next;
    }
};


给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例?1:

输入: 1->1->2
输出: 1->2
示例?2:

输入: 1->1->2->3->3
输出: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
