在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数?m?应当等于给定二叉树的高度。
列数?n?应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:

输入:
      1
     / \
    2   5
   / 
  3 
 / 
4 
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。


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
    int col;
    int height;
    vector<vector<string>> printTree(TreeNode* root) {
        height = GetHeight(root);
        if(height == 0) return {};
        col = (1 << height) - 1;
   
        vector<vector<string> > ans(height,vector<string> (col,""));
        
        dfs(ans,root,0,col/2);
        return ans;
    }

    void dfs(vector<vector<string> >& ans,TreeNode* root,int cur,int cnt)
    {
        if(!root) return;

        ans[cur][cnt] = to_string(root->val);
        //int nextlen = 1<<(height-1 - (cur + 1));
        //防止出现 (height-cur-2) 为负数的情况
        if(!root->left && !root->right) return;
        int nextlen = 1<<(height-cur-2);
        dfs(ans,root->left,cur+1,cnt-nextlen);

        dfs(ans,root->right,cur+1,cnt+nextlen);
    }


    int GetHeight(TreeNode* root)
    {
        if(!root) return 0;

        return 1 + max(GetHeight(root->left),
                    GetHeight(root->right));
    }

};
