给定一个二叉树（具有根结点?root），?一个目标结点?target?，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

?

示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
输出：[7,4,1]
解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。
?

提示：

给定的树是非空的。
树上的每个结点都具有唯一的值?0 <= node.val <= 500?。
目标结点?target?是树上的结点。
0 <= K <= 1000.
通过次数6,088提交次数


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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int> > map;

        dfs(map,root,nullptr);

        queue<int> que;
        que.push(target->val);
        vector<bool> vis(520,false);
        vis[target->val] = true;

        while((k--) > 0 && !que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int f = que.front();
                que.pop();

                for(auto& v : map[f])
                {
                    if(vis[v] == true)  continue;
                    que.push(v);
                    vis[v] = true;
                }
            }
        }

        vector<int> ans;
        while(!que.empty())
        {
            int f = que.front();
            que.pop();

            ans.push_back(f);
        }

        return ans;
    }

    void dfs(unordered_map<int,vector<int> >& map,TreeNode* root,TreeNode* pre)
    {
        if(root == nullptr) return;

        dfs(map,root->left,root);
        if(pre != nullptr)
        {
            map[root->val].push_back(pre->val);
            map[pre->val].push_back(root->val);
        }
        dfs(map,root->right,root);
    }
};
