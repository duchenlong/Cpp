//给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

//请你返回从根到叶子节点的所有路径中?伪回文?路径的数目。




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int arr[10];
    int ans;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root)
    {
        arr[root->val]++;
        
        
        if(root->left)
        {
            dfs(root->left);
        }
        
        if(root->right)
        {
            dfs(root->right);
        }
        if(!root->left && !root->right)
            if(chose()) ans++;
        arr[root->val]--;
    }
    
    bool chose()
    {
        int ret = 0;
        for(int i = 1; i <= 9; i++)
        {
            if(arr[i] & 1) ret++;
            
            if(ret > 1) return false;
        }
        return true;
    }
};
