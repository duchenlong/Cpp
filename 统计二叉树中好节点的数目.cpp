//给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

//「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

// 输入：root = [3,1,4,3,null,1,5]
//输出：4
//解释：图中蓝色节点为好节点。
//根节点 (3) 永远是个好节点。
//节点 4 -> (3,4) 是路径中的最大值。
//节点 5 -> (3,4,5) 是路径中的最大值。
//节点 3 -> (3,1,3) 是路径中的最大值。


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
    int ans = 1;
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        
        dfs(root,root->val);
        
        return ans;
    }
    
    void dfs(TreeNode* root,int maxNum)
    {
        if(!root) return ;
        
        if(root->left)
        {
            TreeNode* node = root->left;
            if(node->val >= maxNum)
            {
                ans++;
               // cout<<node->val<<' ';
                dfs(node,node->val);
            }
            else
            {
                dfs(node,maxNum);
            }
        }
        
        if(root->right)
        {
            TreeNode* node = root->right;
            if(node->val >= maxNum)
            {
                ans++;
               // cout<<node->val<<' ';
                dfs(node,node->val);
            }
            else
                dfs(node,maxNum);
        }
    }
};
