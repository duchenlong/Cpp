//给你一个整数数组?arr 和一个目标值?target ，请你返回一个整数?value?，使得将数组中所有大于?value 的值变成?value 后，数组的和最接近? target?（最接近表示两者之差的绝对值最小）。

//如果有多种使得和最接近?target?的方案，请你返回这些整数中的最小值。

//请注意，答案不一定是?arr 中的数字。

//?

//示例 1：

//输入：arr = [4,9,3], target = 10
//输出：3
//解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
//示例 2：

//输入：arr = [2,3,5], target = 10
//输出：5
//示例 3：

//输入：arr = [60864,25176,27249,21296,20204], target = 56803
//输出：11361

class Solution {
public:
    //偷鸡过了。。。。。
    int findBestValue1(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int len = arr.size();
        int sum = 0;//比他小的数字之和
        int ans = 0;
        int tmp = INT_MAX;
        //直接遍历找数组中的合适的值
        for(int i = 0; i < len; i++) {
            int count = sum + arr[i] * (len - i);
            if(abs(count - target) < tmp) {
                ans = arr[i];
                tmp = abs(count - target);
            }
            sum += arr[i];
        }

        //判断不在数组中的数
        int num = target / len;
        for(int i = num; i < arr[2]; i++) {
            //找数组中第一个比他大的数
            int count = 0;
            for(int j = 0; j < len; j++) {
                if(arr[j] >= i){
                    count += i * (len - j);
                    break;
                }
                count += arr[j];
            }
            if(abs(count - target) < tmp) {
                ans = i;
                tmp = abs(count - target);
            }
        }
        return ans;
    }

    //二分写法
    int findBestValue (vector<int>& arr, int target) {
        int len = arr.size();
        int left = target/len;
        int right = INT_MIN;

        //确定一个数值的边界
        for(auto& eoch : arr) {
            left = min(left,eoch);
            right = max(right,eoch);
        }
        //如果选择一个阈值 value ，使得它对应的 sum 是第 1 个大于等于 target 的，那么目标值可能在 value 也可能在 value - 1。
        while(left < right) {
            int mid = (left + right)>>1;
            int sum = Judge(arr,mid);
            if(sum < target) left = mid + 1;//小于的一定不是最接近的解
            else if(sum >= target) right = mid;
        }

        int sum1 = Judge(arr,left-1);
        int sum2 = Judge(arr,left);
        if(target-sum1 <= sum2 - target) return left-1;
        
        return left;
    }

    int Judge(vector<int>& arr,int pos) {
        int sum = 0;
        for (int num : arr) {
            sum += min(num, pos);
        }
        return sum;
    }
};
