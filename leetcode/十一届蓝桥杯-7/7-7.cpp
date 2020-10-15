#include <iostream>
#include <string>

using namespace std;

int main() {
    string str("");
    cin >> str;
    
    string ans("");
    
    int p = 0;
    int n = str.size();
    while(p < n) {
        char ch = str[p++];
        
        int cnt = 0;
        while(p < n && (str[p] <= '9' && str[p] >= '0')) {
            cnt += cnt * 10 + (str[p++] - '0');
        }
        if(cnt == 0) {
            ans += ch;
            continue;
        }
        
        for(int i = 0; i < cnt; i++) {
            ans += ch;
        }
    }
    
    cout << ans << endl;
    return 0;
}
