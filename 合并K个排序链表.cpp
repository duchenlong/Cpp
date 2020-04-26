//合并?k?个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

//示例:

//输入:
//[
//? 1->4->5,
//? 1->3->4,
//? 2->6
//]
//输出: 1->1->2->3->4->4->5->6


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
    //优先队列
    struct goods {
        int _val;
        ListNode* _node;

        bool operator<(const goods &node) const {
            return _val > node._val;
        }
    };

    priority_queue <goods> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto& node : lists) if(node) q.push({node->val,node});
        ListNode head;
        ListNode* tail = &head;

        while(!q.empty()){
            auto f = q.top();
            q.pop();

            tail->next = f._node;
            tail = tail->next;
            if(f._node->next) q.push({f._node->next->val, f._node->next});
        }
        return head.next;
    }

    //分治思想
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        vector<ListNode*> copy = lists;
        while(copy.size() > 1){
            vector<ListNode*> tmp;
            int num = copy.size();
            for(int l = 0; l < num; l += 2){
                int r = min(num-1,l+1);
                if(l == r) tmp.push_back(copy[l]);
                else tmp.push_back(Merge(copy[l],copy[r]));
            }
            copy = tmp;
        }
        return copy.front();
    }

    ListNode* Merge(ListNode* left, ListNode* right){
        if(!right) return left;
        if(!left) return right;

        ListNode* head = new ListNode;
        ListNode* ret = head;
        while(left && right){
            int l,r;
            l = left->val;
            r = right->val;

            if(l <= r){
                ret = Add(ret,l);
                left = left->next;
            }
            else{
                ret = Add(ret,r);
                right = right->next;
            }
        }

        while(left){
            ret = Add(ret,left->val);
            left = left->next;
        }
        while(right){
            ret = Add(ret,right->val);
            right = right->next;
        }
        ListNode* headnext = head->next;
        delete head;
        return headnext;
    }

    ListNode* Add(ListNode* after, int num){
        ListNode* node = new ListNode(num);
        node->val = num;
        after->next = node;
        return node;
    }
};
