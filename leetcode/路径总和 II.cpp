
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明:?叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和?sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        vector<int> cur;
        cur.push_back(root->val);
        dfs(root,ans,cur,root->val,sum);

        return ans;
    }

    void dfs(TreeNode* root,vector<vector<int>>& ans,vector<int>& cur,int num,int sum)
    {
        if((root->left == nullptr) && (root->right == nullptr))
        {
            if(num == sum)
                ans.push_back(cur);
            return ;
        }

        
        if(root->left)
        {
            cur.push_back(root->left->val);
            dfs(root->left,ans,cur,num + root->left->val,sum);
            cur.pop_back();
        }  
        if(root->right) 
        {
            cur.push_back(root->right->val);
            dfs(root->right,ans,cur,num + root->right->val,sum);
            cur.pop_back();
        }
    }
};
