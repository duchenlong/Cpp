

//两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

//给出两个整数 x 和 y，计算它们之间的汉明距离。

//注意：
//0 ≤ x, y < 231.

//示例:

//输入: x = 1, y = 4

//输出: 2

//解释:
//1   (0 0 0 1)
//4   (0 1 0 0)
//       ↑   ↑

//上面的箭头指出了对应二进制位不同的位置。

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x || y)
        {
            ans += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
        }

        return ans;
    }
};

//两个整数的?汉明距离 指的是这两个数字的二进制数对应位不同的数量。

//计算一个数组中，任意两个数之间汉明距离的总和。

//示例:

//输入: 4, 14, 2

//输出: 6

//解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
//所以答案为：
//HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        vector<int> arr(32);
        for(int i = 0; i < len; i++)
        {
            int j = 0;
            while(nums[i])
            {
                nums[i] & 1 ? (arr[j]++,nums[i] >>= 1) : ( nums[i] >>= 1);
                j++;
            }
        }

        for(int i = 0; i < 32; i++)
        {
            ans += arr[i] * (len - arr[i]);
        }

        return ans;
    }
};
