/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* ri = nullptr;
        ListNode* le = nullptr;
        
        for(int i = 1; i <= n + 1; i++) {
            if(i < m) {
                pre = cur;
                cur = cur->next;
            }else if(i == m) {
                ri = cur;
                le = cur;
            }else {
                ListNode* t = cur->next;
                cur->next = le;
                le = cur;
                cur = t;
            }
        }
        ri->next = cur;
        if(pre) pre->next = le;
        else head = le;
        return head;
    }
};

将一个链表\ m m 位置到\ n n 位置之间的区间反转，要求时间复杂度 ，空间复杂度 。
例如：
给出的链表为 1\to 2 \to 3 \to 4 \to 5 \to NULL1→2→3→4→5→NULL, ，,
返回 1\to 4\to 3\to 2\to 5\to NULL1→4→3→2→5→NULL.
注意：
给出的 满足以下条件：
1 \leq m \leq n \leq 链表长度1≤m≤n≤链表长度
示例1
输入
复制
{1,2,3,4,5},2,4
返回值
复制
{1,4,3,2,5}
