返回与给定的前序和后序遍历匹配的任何二叉树。

?pre?和?post?遍历中的值是不同的正整数。

?

示例：

输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
?

提示：

1 <= pre.length == post.length <= 30
pre[]?和?post[]?都是?1, 2, ..., pre.length?的排列
每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。

只有每个节点度为2或者0的时候前序和后序才能唯一确定一颗二叉树，只有一个子节点是无法确定的，因为无法判断他是左子树还是右子树



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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int l1 = 0;
        int l2 = 0;
        return dfs(pre,l1,pre.size() - 1,
                post,l2,post.size() - 1);
    }

    TreeNode* dfs(vector<int>& pre, int& l1, int r1, 
                vector<int>& post,int& l2, int r2)
    {
        if(l1 > r1 && l2 > r2) return nullptr;

        TreeNode* root = new TreeNode(pre[l1++]);
        //先构建左子树 
        if(root->val != post[l2])
            root->left = dfs(pre,l1,r1,post,l2,r2);
        
        //在构建右子树 
        if(root->val != post[l2])
            root->right = dfs(pre,l1,r1,post,l2,r2);
        l2++;
        return root;
    }
};
