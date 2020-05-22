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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int leni = inorder.size();
        int lenp = postorder.size();

        return dfs(inorder,0,leni-1,postorder,0,lenp-1);
    }

    TreeNode* dfs(vector<int>& inorder,int li,int ri,vector<int>& postorder,int lp,int rp)
    {
        if(li > ri || lp > rp) return NULL;
        TreeNode* root = new TreeNode(postorder[rp]);

        //找到根节点位置
        int pos = Find(inorder,li,ri,postorder[rp]);
        //左子树长度
        int len = pos - li;

        root->left = dfs(inorder,li,pos-1,postorder,lp,lp+len-1);
        root->right = dfs(inorder,pos+1,ri,postorder,lp+len,rp-1);
        return root;
    }

    int Find(vector<int>& arr,int l,int r,int num)
    {
        for(int i = l;i <= r; i++)
            if(arr[i] == num) return i;
        return -1;
    }
};
