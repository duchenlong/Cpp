给定一个数组?nums?，如果?i < j?且?nums[i] > 2*nums[j]?我们就将?(i, j)?称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

示例 1:

输入: [1,3,2,3,1]
输出: 2
示例 2:

输入: [2,4,3,5,1]
输出: 3
注意:

给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。


class Solution {
public:
    vector<int> tmp;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        return merge_sort(nums,0,n-1);
    }

    int merge_sort(vector<int>& nums,int le,int ri)
    {
        if(le >= ri)    return 0;
        int mid = (le + ri) / 2;
        int res = merge_sort(nums,le,mid) + merge_sort(nums,mid+1,ri);
 
        int l = le;
        int r = mid+1;
        for(int i = l ; i <= mid; i++)
        {
            while(r <= ri && nums[i] / 2.0 <= (double)nums[r]) r++;
            res += ri - r + 1; 
        }
        r = mid+1;
        for(int i = le; i <= ri; i++)
        {
            if(l == mid + 1)
            {
                tmp[i] = nums[r];
                r++;
            }
            else if(r == ri + 1)
            {
                tmp[i] = nums[l];
                l++;
            }
            else if(nums[l] > nums[r])
            {
                tmp[i] = nums[l];
                l++;
            }
            else
            {
                tmp[i] = nums[r];
                r++;
            }
        }
        
        for(int i = le; i <= ri; i++)
            nums[i] = tmp[i];
        return res;
    }
};
