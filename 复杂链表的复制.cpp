//请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        
        Node* headNode = head;
        while(headNode)
        {
            Node* next  = headNode->next;
            Node* node = new Node(headNode->val);
            node->next = next;
            headNode->next = node;
            headNode = next;
        }

        headNode = head;
        while(headNode)
        {
            if(headNode->random != NULL)
                headNode->next->random = headNode->random->next;
            headNode = headNode->next->next;
        }

        Node* ret = new Node(0);
        Node* retHead = ret;
        headNode = head;
        while(headNode)
        {
            Node* copy = headNode->next;
            Node* headnext = copy->next;

            ret->next = copy;
            ret = copy;

            headNode->next=headnext;//保持原来的链表
            headNode = headnext;
        }

        ret = retHead->next;
        delete retHead;
        return ret;
    }
};
