//给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

//示例 1:

//输入: [10,2]
//输出: 210
//示例?2:

//输入: [3,30,34,5,9]
//输出: 9534330


class Solution {
public:
    static bool cmp(const string& a,const string& b)
    {
        return a+b > b+a;//30 3 --> 303 330
    }

    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        vector<string> str;

        for(int i = 0; i < len; i++)
            str.push_back(to_string(nums[i]));
        
        sort(str.begin(),str.end(),cmp);
        
        string ans;
        for(int i = 0; i < len; i++)
            ans += str[i];

        return (ans[0]=='0')?"0":ans;
    }
};
