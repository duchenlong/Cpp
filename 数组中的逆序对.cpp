//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

//?

//示例 1:

//输入: [7,5,6,4]
//输出: 5


class Solution {
public:
    //归并排序
    int reversePairs(vector<int>& nums) {
        vector<int> copy = nums;
        int len = nums.size();
        vector<int> tmp(len,0);

        return MergerSlove(copy, 0, len-1, tmp);
    }

    int MergerSlove(vector<int>& copy, int left, int right, vector<int>& tmp){
        //排除只有一个数，或者没有数的情况
        if(left >= right)
            return 0;

        int mid = (left + right) / 2;
        int leftNum = MergerSlove(copy, left, mid, tmp);//左边区间排序
        int rightNum = MergerSlove(copy, mid + 1, right, tmp);//右边区间排序
       
        //如果顺序合并后就是有序区间，就不用合并了
        if(copy[mid] <= copy[mid+1])
            return leftNum + rightNum;
        int mergeNum = MergerAllSlove(copy, left, mid, right, tmp);//合并两个区间

        return leftNum + rightNum + mergeNum;
    }

    int MergerAllSlove(vector<int>& copy, int left, int mid, int right, vector<int>& tmp){
        for(int i = left; i <= right; i++)
            tmp[i] = copy[i];
        
        int l = left;
        int r = mid + 1;
        int count = 0;

        for(int i = left; i <= right; i++){
            if(l == mid + 1)//左边区间元素合并完毕
                copy[i] = tmp[r++];
            else if(r == right + 1)//右边区间元素合并完毕
                copy[i] = tmp[l++];
            else if(tmp[l] <= tmp[r])//左边元素 小于等于 右边元素，不会构成逆序对
                copy[i] = tmp[l++];
            else{//左边元素大于右边元素，构成逆序对
                copy[i] = tmp[r++];
                count += (mid - l + 1); //当前插入元素的后面有多少个左边区间的元素，+1是因为插入就构成了一个逆序对
            }
        }

        return count;
    }
};
