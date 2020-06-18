我们从二叉树的根节点 root?开始进行深度优先搜索。

在遍历中的每个节点处，我们输出?D?条短划线（其中?D?是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出?S，还原树并返回其根节点?root。

?

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
?

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。



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
private:
    string str = "";
    int len = 0;
public:
    TreeNode* recoverFromPreorder1(string S) {
        str = S;
        len = S.size();
        int idx = 0;
        return dfs(idx,0);
    }

    TreeNode* dfs(int& idx,int depth)
    {
        if(idx == len)  return nullptr;

        //找第一个数字，并记录该数字的深度
        int tp = 0;
        while(idx < len && str[idx] == '-')
        {
            idx++;
            tp++;
        }

        //如果当前深度 tp 不符合 depth 就让索引idx回溯到之前的位置
        if(tp < depth)
        {
            idx -= tp;
            return nullptr;
        }
        
        //提取数字
        int num = 0;
        while(idx < len && str[idx] != '-')
            num = num * 10 + str[idx++] - '0';
        
        TreeNode* root = new TreeNode(num);
        root->left = dfs(idx,depth+1);
        root->right = dfs(idx,depth+1);

        return root;
    }

    //非递归
    TreeNode* recoverFromPreorder(string s)
    {
        stack<TreeNode*> st;
        len = s.size();
        int idx = 0;

        while(idx < len)
        {
            //找第一个数字。并且得到他的深度
            int tp = 0;
            while(idx < len && s[idx] == '-')
            {
                idx++;
                tp++;
            }
            //当前所需要的深度节点
            int depth = st.size();

            while(depth != tp && !st.empty())
            {
                st.pop();
                depth--;
            }

            //获取节点的数字
            //提取数字
            int num = 0;
            while(idx < len && s[idx] != '-')
                num = num * 10 + s[idx++] - '0';
            
            TreeNode* node = new TreeNode(num);
            if(!st.empty())  
            {
                TreeNode* top = st.top();
                if(top->left == nullptr)    top->left = node;
                else    top->right = node;
            }
            st.push(node);
        }
        TreeNode* root = new TreeNode();
        while(!st.empty())
        {
            root = st.top();
            st.pop();
        }
        return root;
    }
};
