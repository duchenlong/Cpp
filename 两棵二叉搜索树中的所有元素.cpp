

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
    //存数据，排序 O(logn)
    vector<int> getAllElements1(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1,ans);
        dfs(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& ans)
    {
        if(!root) return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }

    //中序遍历 + 归并排序 O(n + m) 
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        midFind(root1,ans1);
        midFind(root2,ans2);

        vector<int> ans = midSort(ans1,ans2);
        return ans;
    }

    void midFind(TreeNode* root, vector<int>& ans)
    {
        if(!root) return ;
        midFind(root->left,ans);
        ans.push_back(root->val);
        midFind(root->right,ans);
    }

    vector<int> midSort(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> tmp;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int l = 0;
        int r = 0;
        while(l < len1 || r < len2)
        {
            int num = 0;
            if(l < len1 && r < len2)
            {
                if(nums1[l] < nums2[r])
                    tmp.push_back(nums1[l++]);
                else 
                    tmp.push_back(nums2[r++]);
            }
            else if(l < len1)
                tmp.push_back(nums1[l++]);
            else if(r < len2)
                tmp.push_back(nums2[r++]);
        }
        return tmp;
    }
};
