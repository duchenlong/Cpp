//给定一副牌，每张牌上都写着一个整数。

//此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

//每组都有?X?张牌。
//组内所有的牌上都写着相同的整数。
//仅当你可选的 X >= 2 时返回?true。

//?

//示例 1：

//输入：[1,2,3,4,4,3,2,1]
//输出：true
//解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
//示例 2：

//输入：[1,1,1,2,2,2,3,3]
//输出：false
//解释：没有满足要求的分组。
//示例 3：

//输入：[1]
//输出：false
//解释：没有满足要求的分组。
//示例 4：

//输入：[1,1]
//输出：true
//解释：可行的分组是 [1,1]
//示例 5：

//输入：[1,1,2,2,2,2]
//输出：true
//解释：可行的分组是 [1,1]，[2,2]，[2,2]



class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> arr(10005);
        int maxNum = 0;//记录出现的最大数
        for(int i = 0; i < deck.size(); i++)
        {
            arr[deck[i]]++;
            if(deck[i] > maxNum)
                maxNum = deck[i];
        }

        int ans = 0;
        for(int i = 0; i <= maxNum; i++)
        {
            if(!arr[i])//排除没有该数字的情况
                continue;
            if(arr[i] < 2)
                return false;
            ans = gcd(arr[i],ans);
        }
        return ans >= 2;
    }
    //哈希表
    bool hasGroupsSizeX2(vector<int>& deck) {
       //使用哈希表来建立每个值的索引 -- 》 map

        int ans = 0;
        for (int a :map.values())
        {
            if(a < 2)
                return false;
            ans = gcd(ans, a);
        }
        return ans >= 2;
    }

    int gcd(int a,int b)
    {
        return b == 0 ? a : gcd(b,a%b);
    }
};
