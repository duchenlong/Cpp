#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int nums[N];
int len[N];
ll ans = 0;
int n,k;

int GetLen(int num) {
    int ret = 0;
    while(num != 0) {
        num /= 10;
        ret ++;
    }
    return ret;
}

// ³¬Ê± typedef unsigned long long ll;
// void slove() {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j ++)
//             if(i != j && ( (nums[i] * (ll)pow(10,len[j]) + nums[j]) % k == 0 ) ) {
//                 ans++;
//             }
//     }
// }

int cnt[11][N];
void slove() {
    memset(cnt,0x00,sizeof cnt);
    
    for(int i = 0; i < n; i++) {
        ans += cnt[len[i]][(k - nums[i] % k) % k];
        
        long long power = 1;
        for(int j = 0; j < 11; j ++) { 
            cnt[j][power * 1ll * nums[i] % k] ++;
            power = power * 10 % k;
        }
    }
}

int main() {
    cin >> n >> k;
    memset(nums,0x00,sizeof nums);
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        len[i] = GetLen(nums[i]);
    }
    
    slove();
    
    reverse(nums,nums + n);
    reverse(len,len + n);
    
    slove();

    cout << ans << endl;
    return 0;
}
