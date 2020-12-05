class Solution {
public:
    vector<int> ans;
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return maxNumber(nums2,nums1,k);

        
        for(int i = max(0,k - m); i <= k && i <= n; i++) {
            vector<int> arr1 = Getarr(nums1,n,i);
            vector<int> arr2 = Getarr(nums2,m,k - i);
            merge(arr1,i,arr2,k - i);   // 合并区间 + 判断大小
        }

        return ans;
    }

    // 得到数组中 一个k 长度的最大子序列
    vector<int> Getarr(vector<int>& arr,int n,int k) {
        vector<int> ret(k);
        for(int i = 0, j = 0; i < n; i++) {
            while(n - i + j > k && j > 0 && arr[i] > ret[j - 1]) j--;
            if(j < k) ret[j++] = arr[i];
        }

        return ret;
    }

    // 有序区间合并
    void merge(vector<int>& arr1,int n,vector<int>& arr2,int m) {
        vector<int> t(n + m,0);
        int le = 0, ri = 0, idx = 0;
        while(idx < n + m) {
            if(check(arr1,le,arr2,ri)) t[idx++] = arr1[le++];
            else t[idx++] = arr2[ri++];
        }

        if(!check(ans,0,t,0)) ans.swap(t);

        // for(auto& e : t) cout << e << " ";
        // cout << endl;
    }

    bool check(vector<int>& ans,int i,vector<int>& t,int j) {
        int n = ans.size();
        int m = t.size();
        while(i < n && j < m && ans[i] == t[j]) i++,j++;

        return j == m || (i < n && ans[i] > t[j]);
    }
};


给定长度分别为?m?和?n?的两个数组，其元素由?0-9?构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n)?个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为?k?的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例?1:

输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]
示例 2:

输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]
示例 3:

输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-maximum-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
