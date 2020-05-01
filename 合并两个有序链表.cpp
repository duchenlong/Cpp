//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。?

//示例：

//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4


class Solution {
public:
    //迭代写法
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* ret = head;

        while(l1 || l2) {
            if(!l1) {
                ret->next = l2;
                break;
            }
            if(!l2) {
                ret->next = l1;
                break;
            }

            //两串链表都是真
            if(l1->val <= l2->val) {
                ret->next = l1;
                l1 = l1->next;
                ret = ret->next;
            }
            else {
                ret->next = l2;
                l2 = l2->next;
                ret = ret->next;
            }
        }

        ListNode* headNext = head->next;
        delete head;
        return headNext;
    }

    //递归写法
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;//l1是空链表，直接返回l2
        if(!l2) return l1;//l2是空链表，直接返回l1

        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }

        //两个链表都是真 l1比l2的第一个值大
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
};
