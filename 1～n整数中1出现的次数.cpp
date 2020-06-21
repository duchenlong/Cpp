输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

?

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
?

限制：

1 <= n <?2^31


class Solution {
public:
    int countDigitOne1(int n) {
        int ans = 0;
        
        for(int i = 1; i <= n; i++)
        {
            int num = i;
            while(num)
            {
                if(num % 10 == 1)
                    ans++;
                num /= 10;
            }
        }

        return ans;
    }

    int countDigitOne(int n) {
        int ans = 0;
        long i = 1; //i表示哪一位的数字，i = 1表示个位，i = 10 表示十位

        while(n / i != 0)
        {
            //当前位的高位数字
            long high = n / (10 * i);
            //当前位的数字
            long cur = (n / i) % 10;
            //当前位的地位数字
            long low = n - (n / i) * i;

            if(cur == 0)
                ans += high * i;
            else if(cur == 1)
                ans += high * i + low + 1;
            else
                ans += (high + 1) * i;

            i *= 10;
        }
        return ans;
    }
};
