//给你一个?rows x cols?大小的矩形披萨和一个整数 k?，矩形包含两种字符：?'A' （表示苹果）和?'.'?（表示空白格子）。你需要切披萨 k-1 次，得到?k?块披萨并送给别人。

//切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。

//请你返回确保每一块披萨包含?至少?一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。

//?


class Solution {
public:
    const int mod = 1000000007;
    int dp[15][55][55];//dp[k][i][j], 表示第k刀切完，左上角在i,j的切法
    int n,m;
    int num[55][55];//前缀和
    int ways(vector<string>& pizza, int K) {
        int n = pizza.size();
        int m = pizza[0].size();

        //计算前缀和
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                num[i][j] = num[i-1][j] + num[i][j-1] - num[i-1][j-1] + (pizza[i-1][j-1] == 'A');
        
        dp[0][1][1] = 1;
        for(int k = 1; k < K; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                {
                    //判断当前位置的切完后，右下角是否还有苹果
                    if(GetRight(i,j,n,m) <= 0) break;

                    //确保这里是有苹果的
                    for(int x = 1; x < i; x++)//行切割
                    {
                        dp[k][i][j] += dp[k-1][x][j] * (GetRight(x,j,i-1,m)>=1);
                        dp[k][i][j] %= mod;
                    }

                    for(int y = 1; y < j; y++)//纵着切
                    {
                        dp[k][i][j] += dp[k-1][i][y] * (GetRight(i,y,n,j-1)>=1);
                        dp[k][i][j] %= mod;
                    }
                }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans = (ans + dp[K-1][i][j]) % mod;
        return ans;
    }

    int GetRight(int x1,int y1,int x2,int y2)
    {
        return num[x2][y2] - num[x1-1][y2] - num[x2][y1-1] + num[x1-1][y1-1];
    }

};
