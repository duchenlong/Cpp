二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例?1:

输入: [1,3,null,null,2]

?  1
? /
?3
? \
?  2

输出: [3,1,null,null,2]

?  3
? /
?1
? \
?  2
示例?2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
?  /
? 2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
?  /
 ?3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？


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
    void recoverTree1(TreeNode* root) {
        vector<TreeNode*> arr;

        dfs(arr,root);

        int le = 0;
        int ri = arr.size()-1;
        for(int i = 1; i < arr.size(); i++)
            if(arr[i-1]->val > arr[i]->val)
            {
                le = i-1;
                break;
            }
                
        
        for(int i = arr.size() - 2; i >= 0; i--)
            if(arr[i+1]->val < arr[i]->val)
            {
                ri = i+1;
                break;
            }

        int t = arr[le]->val;
        arr[le]->val = arr[ri]->val;
        arr[ri]->val = t;
    }

    void dfs(vector<TreeNode*>& arr,TreeNode* root)
    {
        if(root == nullptr) return ;

        dfs(arr,root->left);
        arr.push_back(root);
        dfs(arr,root->right);
    }


    void recoverTree(TreeNode* root)
    {
        TreeNode* le = nullptr;
        TreeNode* ri = nullptr;
        TreeNode* pre = nullptr;

        DFS(le,ri,pre,root);

        int t = le->val;
        le->val = ri->val;
        ri->val = t;
    }

    void DFS(TreeNode*& le,TreeNode*& ri,TreeNode*& pre,TreeNode* root)
    {
        if(root == nullptr) return ;

        DFS(le,ri,pre,root->left);

        if(pre && pre->val> root->val)
        {
            ri = root;
            if(le == nullptr)    le = pre;
        }
        pre = root;
        
        DFS(le,ri,pre,root->right);
    }
};
