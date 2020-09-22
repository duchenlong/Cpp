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
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        if(root == nullptr) return 0;

        if(dfs(root) == 2) ans++;

        return ans;
    }

    // 0 该节点安装监视器
    // 1 该节点被监视
    // 2 该节点没有被监视
    int dfs(TreeNode* root) {
        if(root == nullptr) return 1;
        int le = dfs(root->left);
        int ri = dfs(root->right);

        if(le == 2 || ri == 2) {    //存在孩子节点没有被监视，该节点加监视器
            ans++;
            return 0;
        } else if(le == 0 || ri == 0) { //孩子节点安装监视器，该节点为被监视状态
            return 1;
        }

        return 2;
    }
};

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

?

示例 1：



输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
示例 2：



输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是?[1, 1000]。
每个节点的值都是 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
