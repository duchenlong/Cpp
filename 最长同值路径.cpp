给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。?树的高度不超过1000。


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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;

        dfs(root,root->val);

        return ans;
    }

    int dfs(TreeNode* root,int val)
    {
        if(root == nullptr) return 0;

        int le = dfs(root->left,root->val);
        int ri = dfs(root->right,root->val);
        ans = max(ans,le + ri);

        if(root->val == val)
            return max(le,ri) + 1;
        return 0;
    }
};
