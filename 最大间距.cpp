//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

//如果数组元素个数小于 2，则返回 0。

//示例?1:

//输入: [3,6,9,1]
//输出: 3
//解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
//示例?2:

//输入: [10]
//输出: 0
//解释: 数组元素个数小于 2，因此返回 0。


class Solution {
public:
    struct goods {
        bool _isHave = false;
        int _min = INT_MAX;
        int _max = INT_MIN;
    };
	//桶排序 O(n) 
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        //求所有数据中最大值，最小值
        for(auto& eoch : nums){
            minNum = min(eoch, minNum);
            maxNum = max(eoch, maxNum);
        }

        //桶的长度  [2,,4,6,8] --> (8 - 2) / (4 - 1) = 2
        //[2,4) [4,6) [6, 8)
        int bucketLen = max(1,(maxNum - minNum) / (len - 1));
        //桶的数量
        int bucketNum = (maxNum - minNum) / bucketLen + 1;//为了让桶变成左闭右闭区间
        vector<goods> buckets(bucketNum);

        for(auto& eoch : nums){
            //计算当前数字在哪一个桶中
            int ret = (eoch - minNum) / bucketLen;
            buckets[ret]._isHave = true;
            buckets[ret]._min = min(buckets[ret]._min, eoch);
            buckets[ret]._max = max(buckets[ret]._max, eoch);
        }
        int ans = 0;
        int afterMax = INT_MIN;//前一个有效的桶的最大值
        for(auto& bucket : buckets){
            if(bucket._isHave == false) continue;
            //如果前一个桶存在，就当前桶最小值与前一个桶最大值的差距
            if(afterMax != INT_MIN) ans = max(ans, bucket._min - afterMax);
            ans = max(ans, bucket._max - bucket._min);
            afterMax = bucket._max; //更新前一个桶的最大值
        }
        return ans;
    }

    //排序 O(nlogn)
    int maximumGap1(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return 0;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right < len){
            ans = max(ans,nums[right] - nums[left]);
            right++;
            left++;
        }
        return ans;
    }
}
