给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。

回想一下：

叶节点 是二叉树中没有子节点的节点
树的根节点的?深度?为?0，如果某一节点的深度为?d，那它的子节点的深度就是?d+1
如果我们假定 A 是一组节点?S?的 最近公共祖先，S?中的每个节点都在以 A 为根节点的子树中，且 A?的深度达到此条件下可能的最大值。
?

示例 1：

输入：root = [1,2,3]
输出：[1,2,3]
解释： 
最深的叶子是值为 2 和 3 的节点。
这些叶子的最近共同祖先是值为 1 的节点。
返回的答案为序列化的 TreeNode 对象（不是数组）"[1,2,3]" 。
示例 2：

输入：root = [1,2,3,4]
输出：[4]
示例 3：

输入：root = [1,2,3,4,5]
输出：[2,4,5]
?

提示：

给你的树中将有?1 到 1000 个节点。
树中每个节点的值都在 1 到 1000 之间。

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
    unordered_map<TreeNode*,int> map_t;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == nullptr) return nullptr;

        int le = depth(root->left);
        int ri = depth(root->right);
        if(le == ri)    return root;

        return le < ri ?  lcaDeepestLeaves(root->right) : lcaDeepestLeaves(root->left);
    }

    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        if(map_t.count(root) > 0)   return map_t[root];

        int le = depth(root->left);
        int ri = depth(root->right);
        return 1 + max(le, ri);
    }
};
