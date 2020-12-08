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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* le = nullptr;
        ListNode* ri = nullptr;
        ListNode* lePre = nullptr;
        ListNode* cur = head;

        for(int i = 1; i <= n + 1; i++) {
            if(i < m) {
                lePre = cur;
                cur = cur->next;
            } else if(i == m) {
                le = cur;
                ri = cur;
            } else {
                ListNode* curNetx = cur->next;
                cur->next = ri;
                ri = cur;
                cur = curNetx;
            }
        }

        if(lePre) lePre->next = ri;
        else head = ri;
        le->next = cur;
        return head;
    }
};
