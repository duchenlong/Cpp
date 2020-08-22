你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过?*，/，+，-，(，)?的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符?/?表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用?-?作为一元运算符。例如，[1, 1, 1, 1]?作为输入时，表达式?-1 - 1 - 1 - 1?是不允许的。

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp;
        for(int i = 0; i < 4; i++)
            tmp.push_back((double)nums[i]);

        return dfs(tmp);
    }

    bool dfs(vector<double>& nums)
    {
        int n = nums.size();
        if(n == 0)    return false;
        if(n == 1)    return fabs(nums[0] - 24) < 1e-6;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == j)  continue;
                vector<double> tmp;
                for(int k = 0; k < n; k++)
                    if(k != i && k != j)    tmp.push_back(nums[k]);

                for(int k = 0; k < 4; k++)
                {
                    if(k == 3 && fabs(nums[j]) < 1e-6 )    continue;
                    if((k == 0 || k == 2) && i > j) continue;

                    double num = check(nums[i],nums[j],k);
                    tmp.push_back(num);
                    if(dfs(tmp))    return true;
                    tmp.pop_back();
                }   
            }
            

        return false;
    }

    double check(double a,double b,int oper)
    {
        if(oper == 0)   return a+b;

        if(oper == 1)   return a-b;

        if(oper == 2)   return a*b;

        return a/b;
    }
};
