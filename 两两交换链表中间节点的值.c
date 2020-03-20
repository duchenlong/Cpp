//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 

//示例:

//给定 1->2->3->4, 你应该返回 2->1->4->3.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* swapPairs(struct ListNode* head){
    ListNode* two = head;
    ListNode* three = head;
    //定义一个新的头结点
    ListNode* newhead = (ListNode*)malloc(sizeof(ListNode));
    newhead->next = head;
    ListNode* one = newhead;
    
    while(two)
    {
        three = two->next;
        if(three)
        {
            //交换
            two->next = three->next;
            one->next = three;
            three->next = two;

            //one->three->two
            one = two;
            
        }
        two = two->next;
    }
    head = newhead->next;
    free(newhead);
    return head;
}
