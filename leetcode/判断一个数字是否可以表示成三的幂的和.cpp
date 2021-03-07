class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> f;
        int num = 1;
        while(num <= n) {
            f.push_back(num);
            num *= 3;
        }
        
        
        
        return dfs(f,0,n);
    }
    
    bool dfs(vector<int>& f,int id,int n) {
        if(n < 0) return false;
        if(n == 0) return true;
        
        for(int i = id; i < f.size(); i++) {
            n -= f[i];
            if(dfs(f,i + 1,n)) return true;
            n += f[i];
        }
        
        return false;
    }
};


class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n) {
            if(n % 3 == 2) 
                return false;
            n /= 3; 
        }

        return true;
    }
};


给你一个整数?n?，如果你可以将?n?表示成若干个不同的三的幂之和，请你返回?true?，否则请返回 false?。

对于一个整数 y?，如果存在整数 x?满足 y == 3x?，我们称这个整数 y?是三的幂。

?

示例 1：

输入：n = 12
输出：true
解释：12 = 31 + 32
示例 2：

输入：n = 91
输出：true
解释：91 = 30 + 32 + 34
示例 3：

输入：n = 21
输出：false
?

提示：

1 <= n <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-number-is-a-sum-of-powers-of-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
