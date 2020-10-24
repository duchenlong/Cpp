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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* pre = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse
        ListNode* mid = slow;\
        if(pre) pre->next = nullptr;
        ListNode* next = slow->next;
        while(next) {
            ListNode* nnext = next->next;
            next->next = slow;
            slow = next;
            next = nnext;
        }

        // check
        ListNode* le = head;
        ListNode* ri = slow;
        while(le) {
            if(le->val != ri->val) return false;
            le = le->next;
            ri = ri->next;
        }

        return true;
    }
};


请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用?O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
