//你将获得?K?个鸡蛋，并可以使用一栋从?1?到?N??共有 N?层楼的建筑。

//每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

//你知道存在楼层?F ，满足?0 <= F <= N 任何从高于 F?的楼层落下的鸡蛋都会碎，从?F?楼层或比它低的楼层落下的鸡蛋都不会破。

//每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层?X?扔下（满足?1 <= X <= N）。

//你的目标是确切地知道 F 的值是多少。

//无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

//?

//示例 1：

//输入：K = 1, N = 2
//输出：2
//解释：
//鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
//否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
//如果它没碎，那么我们肯定知道 F = 2 。
//因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
//示例 2：

//输入：K = 2, N = 6
//输出：3
//示例 3：

//输入：K = 3, N = 14
//输出：4
//哭了 


class Solution {
public:
    //递归
    int superEggDrop1(int k, int N) {
        if(k <= 1 || N <= 1)
            return N;
        int maxAns = N;
        for(int i = 1; i <= N; i++)
        {
            //(k-1,i-1)   当前层摔坏了，鸡蛋-1，验证是第i层的问题，还是前i层的问题
            //(k,N-i)  当前层没有摔坏，需要去上面的 N-i 层检测
            int tmax = max(superEggDrop(k-1,i-1), superEggDrop(k,N-i));
            maxAns = min(maxAns,tmax + 1);//tmax + 1  1表示第i层摔一次
        }
        return maxAns;
    }

    //优化
    int superEggDrop2(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));

        for(int i = 1; i <= N; i++)
            dp[1][i] = i;//只有一个鸡蛋
        
        for(int egg = 2; egg <= k; egg++)//所用的鸡蛋数
        {
            for(int n = 1; n <= N; n++)//当前楼层数
            {
                int maxDrop = N + N;
                for(int x = 1; x <= n; x++)
                {
                    int tMin = max(dp[egg-1][x-1],dp[egg][n-x]);
                    maxDrop = min(maxDrop,tMin + 1);
                }
                dp[egg][n] = maxDrop;
            }
        }

        return dp[k][N];
    }

    int superEggDrop3(int k, int N) {
        vector<int> dp(N+1,0);

        for(int i = 1; i <= N; i++)//1个鸡蛋
            dp[i] = i;

        //多个鸡蛋
        for(int egg = 2; egg <= k; egg++)
        {
            vector<int> dp2(N+1,0);//第egg个鸡蛋可以测的楼层数
            int x = 1;//从第一层开始
            for(int n = 1; n <= N; n++)
            {
                //max(dp[x-1],dp2[n-x]) > max(dp[x], dp2[n-x-1]
                //T1 =dp(K?1,X?1)，T2 =dp(K,N?X)
                //max(T1(x-1), T2(x-1)) > max(T1(x), T2(x))
                while(x < n && 
                    max(dp[x-1],dp2[n-x]) > max(dp[x], dp2[n-x-1]))
                    x++;
                dp2[n] = 1 + max(dp[x-1],dp2[n-x]);
            }

            dp = dp2;
        }

        return dp[N];
    }

     //优化
    int superEggDrop4(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));// k个鸡蛋在n步可以测出多少层楼

        for(int n = 1; n <= N; n++)
        {
            for(int egg = 1; egg <= k; egg++)
            {
                //dp[egg][n]  -->  第egg个鸡蛋在n-1测出的楼层数 + 当前楼层(1) == dp[egg][n-1] + 1;
                //前面egg-1个鸡蛋在n-1步测出的楼层数 == dp[egg-1][n-1]
                dp[egg][n] = dp[egg][n-1] + dp[egg-1][n-1] + 1;
                if(dp[egg][n] >= N)
                    return n;
            }
        }
        return N;
    }

     //优化
    int superEggDrop(int k, int N) {
        vector<vector<int> > dp(k+1,vector<int>(N+1,0));

        int m = 0;
        while(dp[k][m] < N)
        {
            m++;
            for(int egg = 1; egg <= k; egg++)
                dp[egg][m] = 1 + dp[egg-1][m-1] + dp[egg][m-1];
        }

        return m;
    }
};
