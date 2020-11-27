class Solution {
public:
    struct goods {
        bool _isHave = false;
        int _min = INT_MAX;
        int _max = INT_MIN;
    };

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for(auto& e : nums) minNum = min(minNum,e),maxNum = max(maxNum,e);

        int bucketLen = max(1,(maxNum - minNum) / (n - 1));
        int bucketCnt = (maxNum - minNum) / bucketLen + 1;
        vector<goods> arr(bucketCnt);
        for(auto& e : nums) {
            int p = (e - minNum) / bucketLen;
            arr[p]._isHave = true;
            arr[p]._min = min(arr[p]._min, e);
            arr[p]._max = max(arr[p]._max, e);
        }

        int ans = 0;
        int afterMax = INT_MIN;
        for(auto& e : arr) {
            if(!e._isHave) continue;
            if(afterMax != INT_MIN) ans = max(ans,e._min - afterMax);
            ans = max(ans,e._max - e._min);
            afterMax = e._max;
        }

        return ans;
    }
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        int maxNum = INT_MIN;
        for(auto& e : nums) maxNum = max(maxNum, e);

        vector<int> buf(n);
        int exp = 1;
        while(maxNum >= exp) {
            vector<int> cnt(10,0);
            for(auto& e : nums) cnt[(e / exp) % 10] ++;
            for(int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];

            for(int i = n - 1; i >= 0; i--) 
                buf[-- cnt[(nums[i] / exp) % 10]] = nums[i];
              
            nums.swap(buf);
            exp *= 10;
        }

        int ans = 0;
        for(int i = 1; i < n; i++) ans = max(ans,nums[i] - nums[i - 1]);
        return ans;
    }
};


给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例?1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例?2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-gap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
