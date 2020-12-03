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
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        ListNode* le = Reverse(head1);
        ListNode* ri = Reverse(head2);
        
        int num = 0;
        ListNode* head = new ListNode(-1);
        head->next = NULL;
        ListNode* cur = head;
        
        while(le || ri || num) {
            if(le) {
                num += le->val;
                le = le->next;
            }
            if(ri) {
                num += ri->val;
                ri = ri->next;
            }
            ListNode* t = new ListNode(num % 10);
            num /= 10;
            cur->next = t;
            cur = cur->next;
            
        }
        
        ListNode* ret = head->next;
        head->next = NULL;
        return Reverse(ret);
    }
    
private:
    ListNode* Reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ret = Reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};

假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。
示例1
输入
复制
[9,3,7],[6,3]
返回值
复制
{1,0,0,0}
备注:
1 \leq n, m \leq 10^61≤n,m≤10 
6
 
0 \leq a_i, b_i \leq 90≤a 
i
?	
 ,b 
i
?	
 ≤9
