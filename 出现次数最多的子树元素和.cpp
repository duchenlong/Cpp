给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

?

示例 1：
输入:

  5
 /  \
2   -3
返回?[2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。

示例?2：
输入：

  5
 /  \
2   -5
返回?[2]，只有 2 出现两次，-5 只出现 1 次。

?

提示：?假设任意子树元素和均可以用 32 位有符号整数表示。



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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        map<int,int> mp;
        int count = INT_MIN;

        for(auto& eoch : ans)
        {
            mp[eoch]++;
            if(mp[eoch] > count)
                count = mp[eoch];
        }

        vector<int> ret;
        for(auto& eoch : mp)
            if(eoch.second == count)
                ret.push_back(eoch.first);
        return ret;
    }

    int dfs(TreeNode* root,vector<int>& ans)
    {
        if(!root)
            return 0;
        
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        ans.push_back(left + right + root->val);
        return left + right + root->val;
    }
};
