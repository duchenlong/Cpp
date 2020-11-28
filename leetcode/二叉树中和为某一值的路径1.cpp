/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> t;
    vector<vector<int> > FindPath(TreeNode* root,int e) {
        if(!root) return ans;
        
        dfs(root,e);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void dfs(TreeNode* root, int e) {
        if(root == nullptr) return ;
        e -= root->val;
        t.push_back(root->val);
        if(!root->left && !root->right) {
            if(e == 0) ans.push_back(t);
            t.pop_back();
            return ;
        }
        
        dfs(root->left,e);
        dfs(root->right,e);
        t.pop_back();
    }
};

输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
