输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回?true，否则返回?false。假设输入的数组的任意两个数字都互不相同。

?

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
?

提示：

数组长度 <= 1000

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();
        
        return dfs(postorder,0,n-1);
    }

    bool dfs(vector<int>& arr,int le,int ri){
        if(le >= ri)    return true;

        int idx = le;
        while(idx < ri && arr[idx] < arr[ri]){
            idx++;
        }

        // [le,idx) left
        // [idx,ri-1] right
        for(int i = idx + 1; i < ri; i++){
            if(arr[i] < arr[ri])    return false;
        }

        return dfs(arr,le,idx-1) && dfs(arr,idx,ri-1);
    }
};
