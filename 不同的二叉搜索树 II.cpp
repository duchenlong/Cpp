给定一个整数 n，生成所有由 1 ...?n 为节点所组成的 二叉搜索树 。

?

示例：

输入：3
输出：
[
? [1,null,3,2],
? [3,2,null,1],
? [3,1,null,null,2],
? [2,1,3],
? [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
?

提示：

0 <= n <= 8


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
    vector<TreeNode*> generateTrees(int n) {
        if(n != 0) return dp(1,n);
        
        return vector<TreeNode*> {};
    }

    vector<TreeNode*> dp(int le,int ri)
    {
        vector<TreeNode*> ans;
        if(le > ri)
        {
            ans.push_back(nullptr);
            return ans;
        }

        for(int i = le; i <= ri; i++)
        {
            vector<TreeNode*> left_nodes = dp(le,i-1);
            vector<TreeNode*> right_nodes = dp(i+1,ri);

            for(auto& left : left_nodes)
                for(auto& right : right_nodes)
                {
                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
        }

        return ans;
    }
};
