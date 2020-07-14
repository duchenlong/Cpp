从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。给定一个由不同节点组成的二叉搜索树，输出所有可能生成此树的数组。

?

示例：
给定如下二叉树

        2
       / \
      1   3
返回：

[
   [2,1,3],
   [2,3,1]
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
    int sum = 0;
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if(root == nullptr) return {{}};
        
        vector<vector<int> > ans;
        vector<int> buf;
        deque<TreeNode*> que;
        que.push_back(root);

        check(ans,buf,que);
        return ans;
    }

    void check(vector<vector<int> >& ans,vector<int>& buf,deque<TreeNode*>& que)
    {
        if(que.empty())
        {
            ans.push_back(buf);
            return;
        }

        size_t size = que.size();
        while(size--)
        {
            auto f = que.front();
            que.pop_front();

            buf.push_back(f->val);
            int child = 0;
            if(f->left)
            {
                child++;
                que.push_back(f->left);
            }
            if(f->right)
            {
                child++;
                que.push_back(f->right);
            }
            check(ans,buf,que);

            while(child--)
                que.pop_back();
            que.push_back(f);
            buf.pop_back();
        }

    }
};
