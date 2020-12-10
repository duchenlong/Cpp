/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*> que;
        que.push(tree);

        vector<ListNode*> ans;
        if(tree == nullptr) return ans;
        ListNode* head = new ListNode(-1);
        while(!que.empty()) {
            int size = que.size();
            head->next = nullptr;
            ListNode* cur = head;

            while(size --) {
                TreeNode* f = que.front();
                que.pop();

                if(f->left) que.push(f->left);
                if(f->right) que.push(f->right);
                ListNode* t = new ListNode(f->val);
                cur->next = t;
                cur = cur->next;
            }
            ans.push_back(head->next);
        }

        return ans;
    }
};

给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D 个链表）。返回一个包含所有深度的链表的数组。

?

示例：

输入：[1,2,3,4,5,null,7,8]

        1
       /  \ 
      2    3
     / \    \ 
    4   5    7
   /
  8

输出：[[1],[2,3],[4,5,7],[8]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/list-of-depth-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
