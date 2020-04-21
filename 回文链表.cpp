//编写一个函数，检查输入的链表是否是回文的。

//?

//示例 1：

//输入： 1->2
//输出： false 
//示例 2：

//输入： 1->2->2->1
//输出： true 



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
        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        //找到中间节点的位置
        //奇数个节点，快指针会停在最后一个节点位置，fast->next为NULL退出
        //偶数个节点，快指针会停在NULL的位置，fast为NULL
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //翻转前半段
        
        ListNode* node = head;
        ListNode* next = head->next;
        head->next = NULL;
        while(next != slow){
            ListNode* nextnode = next->next;
            next->next = node;
            node = next;
            next = nextnode;
        }

        //找到后半段的头
        ListNode* mid;
        if(fast)
            mid = slow->next;
        else
            mid = slow;
        slow = node;
        while(mid){
            if(slow->val != mid->val)
                return false;
            slow = slow->next;
            mid = mid->next;
        }

        return true;
    }
};
