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
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = new ListNode(-1);
        ListNode* cle = le;
        ListNode* ri = new ListNode(-1);
        ListNode* cri = ri;

        while(head) {
            ListNode* headNext = head->next;
            head->next = nullptr;
            if(head->val < x) {
                cle->next = head;
                cle = cle->next;
            } else {
                cri->next = head;
                cri = cri->next;
            }
            head = headNext;
        }

        cle->next = ri->next;
        return le->next;
    }
};
