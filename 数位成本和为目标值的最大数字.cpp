//给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

//给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
//总成本必须恰好等于 target 。
//添加的数位中没有数字 0 。
//由于答案可能会很大，请你以字符串形式返回。

//如果按照上述要求无法得到任何整数，请你返回 "0" 。
//示例 1：

//输入：cost = [4,3,2,5,6,7,2,5,5], target = 9
//输出："7772"
//解释：添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "997" 也是满足要求的数字，但 "7772" 是较大的数字。
// 数字     成本
//  1  ->   4
//  2  ->   3
//  3  ->   2
//  4  ->   5
//  5  ->   6
//  6  ->   7
//  7  ->   2
//  8  ->   5
//  9  ->   5

class Solution {
public:
    
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1);
        for(int i = 0; i <= target; i++)
        {
            if(i != 0 && dp[i]=="") continue;
            
            for(int j = 1; j <= 9; j++)
            {
                if(i + cost[j-1] > target) continue;
                auto tmp = dp[i] + to_string(j);
                dp[i + cost[j-1]] = FunB(dp[i + cost[j-1]], tmp) ? dp[i + cost[j-1]] : tmp;
            }
        }
        
        return dp.back()=="" ? "0":dp.back();
    }
    
    bool FunB(string& l,string& r)
    {
        if(l.size() != r.size())
            return l.size() > r.size();
        
        return strcmp(l.c_str(),r.c_str()) > 0;
    }
};
