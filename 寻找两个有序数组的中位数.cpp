//给定两个大小为 m 和 n 的有序数组?nums1 和?nums2。

//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为?O(log(m + n))。

//你可以假设?nums1?和?nums2?不会同时为空。

//示例 1:

//nums1 = [1, 3]
//nums2 = [2]

//则中位数是 2.0
//示例 2:

//nums1 = [1, 2]
//nums2 = [3, 4]

//则中位数是 (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        //确保num1 比 num2 数组大
        if(len1 < len2)
            return findMedianSortedArrays(nums2,nums1);

        int n = len1 + len2;

        //传参为[] ,左闭右闭区间
        if(n & 1)//两个数组长度为奇数
            return Find_Binary(nums1,0,len1-1,\
                                nums2,0,len2-1,(n>>1) + 1);//找第k小
        
        //两个数组长度和为偶数   找第k和第k+1小
        return (Find_Binary(nums1,0,len1-1,nums2,0,len2-1,n>>1) \
            + Find_Binary(nums1,0,len1-1,nums2,0,len2-1,(n>>1) + 1)) / 2.0;
    }

    //二分查找第k小
    int Find_Binary(vector<int>& nums1,int l1,int r1,\
                    vector<int>& nums2,int l2,int r2,int k)//二分找第k小
    {
        if(l1 > r1)//如果数组1元素都不符合，或者数组1是空
            return nums2[l2 + k - 1];
        
        if(l2 > r2)//如果数组2元素都不符合，或者数组2是空
            return nums1[l1 + k - 1];

        if(k == 1)//如果找第一个小的，返回两数组最左边小的那一个
            return min(nums1[l1],nums2[l2]);

        //找到两数组k/2位置
        int d1 = l1 + k / 2 - 1;
        int d2 = l2 + k / 2 - 1;

        //排除越界的情况
        d1 = (d1 <= r1) ? d1 : r1;
        d2 = (d2 <= r2) ? d2 : r2;

        //两种情况
        //1.数组1 k/2位置的值比 数组2 小，删除数组1前 (d1 - l1 + 1) 个元素
        if(nums1[d1] < nums2[d2])
            return Find_Binary(nums1,d1 + 1,r1,nums2,l2,r2,k - (d1 - l1 + 1));

        //2.数组1 k/2位置的值比 数组2 大，删除数组2前 (d2 - l2 + 1) 个元素
        return Find_Binary(nums1,l1,r1,nums2,d2 + 1,r2, k - (d2 - l2 + 1));
    }
};
