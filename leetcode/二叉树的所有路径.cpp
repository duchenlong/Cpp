给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明:?叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;

        dfs("",ans,root);
        return ans;
    }

    void dfs(string str,vector<string>& ans,TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(str + to_string(root->val));
            return ;
        }

        dfs(str + to_string(root->val) + "->",ans,root->left);
        dfs(str + to_string(root->val)  + "->",ans,root->right);
    }
};
