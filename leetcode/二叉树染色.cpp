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
    int maxValue(TreeNode* root, int k) {
        vector<int> f = dfs(root,k);
        int res = 0;
        for(int i = 0 ; i <= k; i ++)
            res = max(res,f[i]);
        
        return res;
    }

private:
    vector<int> dfs(TreeNode* root,int k) {
        vector<int> res(k + 1);
        if(root == nullptr)
            return res;
        
        vector<int> le = dfs(root->left,k);
        vector<int> ri = dfs(root->right,k);

        for(int i = 0; i < k; i ++)
            for(int j = 0; j + i + 1 <= k; j ++)
                res[i + j + 1] = max(res[i + j + 1], root->val + le[i] + ri[j]);
        
        for(int i = 0; i <= k; i ++)
            for(int j = 0; j <= k; j ++)
                res[0] = max(res[0],le[i] + ri[j]);
        
        return res;
    }
};


小扣有一个根结点为 root 的二叉树模型，初始所有结点均为白色，可以用蓝色染料给模型结点染色，模型的每个结点有一个 val 价值。小扣出于美观考虑，希望最后二叉树上每个蓝色相连部分的结点个数不能超过 k 个，求所有染成蓝色的结点价值总和最大是多少？

示例 1：

输入：root = [5,2,3,4], k = 2

输出：12

解释：结点 5、3、4 染成蓝色，获得最大的价值 5+3+4=12


示例 2：

输入：root = [4,1,3,9,null,null,2], k = 2

输出：16

解释：结点 4、3、9 染成蓝色，获得最大的价值 4+3+9=16


提示：

1 <= k <= 10
1 <= val <= 10000
1 <= 结点数量 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-ran-se-UGC
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
