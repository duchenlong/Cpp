
给你一棵二叉树，请你返回层数最深的叶子节点的和。

?

示例：



输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
?

提示：

树中节点数目在?1?到?10^4?之间。
每个节点的值在?1?到?100 之间。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty())
        {
            int size = que.size();

            int num = 0;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                num += node->val;
            }

            ans = num;
        }
        return ans;
    }
};
