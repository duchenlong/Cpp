#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1000 * 100 + 10;
int f[N],n,id;

int main() {
    cin >> n;
    while(n --) {
        while(cin >> f[id++]);
    }
    
    sort(f,f+id);
    int a,b;
    for(int i = 1; i < id; i++) {
        if(f[i] == f[i-1]) b = f[i];
        else if(f[i] != f[i - 1] + 1) a = f[i] - 1;
    }
    cout << a << " " << b << endl;
    return 0;
}

某涉密单位下发了某种票据，并要在年终全部收回。

每张票据有唯一的ID号。

全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。

因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。

你的任务是通过编程，找出断号的ID和重号的ID。

假设断号不可能发生在最大和最小号。

输入格式
第一行包含整数 N，表示后面共有 N 行数据。

接下来 N 行，每行包含空格分开的若干个（不大于100个）正整数（不大于100000），每个整数代表一个ID号。

输出格式
要求程序输出1行，含两个整数 m,n，用空格分隔。

其中，m表示断号ID，n表示重号ID。

数据范围
1≤N≤100
输入样例：
2
5  6  8  11  9
10  12  9
输出样例：
7 9
