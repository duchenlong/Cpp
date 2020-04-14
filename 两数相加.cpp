给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

?

进阶：

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

?

示例：

输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        AddStack(st1,l1);
        AddStack(st2,l2);
        int num = 0;//进位
        ListNode* head = NULL;

        while(!st1.empty() || !st2.empty() || num)
        {
            if(!st1.empty())
            {
                num += st1.top();
                st1.pop();
            }

            if(!st2.empty())
            {
                num += st2.top();
                st2.pop();
            }

            ListNode* ret = new ListNode(num%10);
            ret->next = head;
            head = ret;
            num /= 10;
        }

        return head;
    }

    void AddStack(stack<int>& st, ListNode* list)
    {
        while(list)
        {
            st.push(list->val);
            list = list->next;
        }
    }
};


