//给定整数数组 A，每次 move 操作将会选择任意?A[i]，并将其递增?1。

//返回使 A?中的每个值都是唯一的最少操作次数。

//示例 1:

//输入：[1,2,2]
//输出：1
//解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
//示例 2:

//输入：[3,2,1,2,1,7]
//输出：6
//解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
//可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。

class Solution {
public:
    
    //排序，O(nlog(n))
    int minIncrementForUnique1(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;

        for(int i = 1; i < A.size(); i++){
            if(A[i] <= A[i-1]){
                ans += A[i-1] + 1 - A[i];
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
    //计数排序  O(N + K)
    int minIncrementForUnique2(vector<int>& A) {
        int len = A.size();
        if(len <= 1)
            return 0;
        int maxValue = 0;
        vector<int> arr1(80004);//防止出现全部都是最大数的情况
        for(size_t i = 0; i < len; i++){
            arr1[A[i]]++;
            maxValue = max(A[i],maxValue);
        }
        int ans = 0;
        maxValue <<= 1;

        for(int i = 0; i <= maxValue; i++){
            if(arr1[i] > 1){
                ans += arr1[i] - 1;//当前位置只能有一个值，所以其他值都得+1
                arr1[i+1] += arr1[i] - 1;//+1移动到后面的位置
                arr1[i] = 1;
            }
        }

        return ans;
    }

    //路径压缩 O(n) 
    vector<int> arr{vector<int> (80000,-1)};//-1表示空位
    int minIncrementForUnique(vector<int>& A){
        int ans = 0;
        for(int start : A){
            int end = findPos(start);
            ans += end - start;
        }
        return ans;
    }

    int findPos(int start){
        int end = arr[start];
        //如果是空位，直接放在这个位置就可以
        if(end == -1){
            arr[start] = start;
            return start;
        }

        //不是空位，直接跳到下一个空位
        end = findPos(end + 1);
        arr[start] = end; //以便下一次访问的时候直接跳到可以插入的位置
        return end;
    }
};
