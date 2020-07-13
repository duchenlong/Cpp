给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果?nums1?的大小比?nums2?小很多，哪种方法更优？
如果?nums2?的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办


class Solution {
public:
    //哈希表技术
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return intersect(nums2,nums1);
        unordered_map<int,int> map;
        for(auto& n : nums1)
            map[n]++;
        
        vector<int> ans;
        for(auto& n : nums2)
            if(map[n] > 0) ans.push_back(n),map[n]--;
        return ans;
    }

    //排序
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int le = 0,ri = 0;
        vector<int> ans;
        while(le < nums1.size() && ri < nums2.size())
        {
            if(nums1[le] == nums2[ri])
            {
                ans.push_back(nums2[ri]);
                le++;
                ri++;
                continue;
            }

            //le  != ri
            if(nums1[le] < nums2[ri])
                le++;
            else
                ri++;
        }
        return ans;
    }

};
