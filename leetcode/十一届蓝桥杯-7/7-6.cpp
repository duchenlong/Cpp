#include <iostream>

using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    
    while(n != 0) {
        cout << n << " ";
        n /= 2;
    }
    
    cout << endl;
    return 0;
}
