#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int N = 50;
const int M = 50;
int dp[N][M];

int n,m;

int main() {
    cin >> n >> m;
    memset(dp,0x00,sizeof dp);
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= n ; i++)
        for(int j = 1; j <= m; j++) {
            if(((i & 1) == 0) && ((j & 1) == 0)) continue;
            
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    cout << dp[n][m] << endl;
    return 0;
}
