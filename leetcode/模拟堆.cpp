维护一个集合，初始时集合为空，支持如下几种操作：

“I x”，插入一个数x；
“PM”，输出当前集合中的最小值；
“DM”，删除当前集合中的最小值（数据保证此时的最小值唯一）；
“D k”，删除第k个插入的数；
“C k x”，修改第k个插入的数，将其变为x；
现在要进行N次操作，对于所有第2个操作，输出当前集合的最小值。

输入格式
第一行包含整数N。

接下来N行，每行包含一个操作指令，操作指令为”I x”，”PM”，”DM”，”D k”或”C k x”中的一种。

输出格式
对于每个输出指令“PM”，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

数据范围
1≤N≤105
?109≤x≤109
数据保证合法。

输入样例：
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
输出样例：
-10
6

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int f[N],idx;
int hp[N],ph[N];    // hp[i] 堆中的第i个点对应的第hp[i]次插入  ph[i] 第i次插入的数在堆中的下标
int n,a,b;

// 大于号，建小堆
bool comper(const int le,const int ri) {
    return f[le] > f[ri];
}

void heap_swap(const int le,const int ri) {
    swap(ph[hp[le]],ph[hp[ri]]);
    swap(hp[le],hp[ri]);
    swap(f[le],f[ri]);
}

// 向上调整
void push(const int x) {
    int ch = x;
    int fa = x / 2;
    while(fa) {
        if(comper(fa,ch)) {
            heap_swap(fa,ch);
        } else {
            break;
        }
        ch = fa;
        fa = ch / 2;
    }
}

// 向下调整
void pop(const int x) {
    int fa = x;
    int ch = fa * 2;
    while(ch <= idx) {
        if(ch < idx && comper(ch,ch + 1)) ch ++;
        if(comper(fa,ch)) {
            heap_swap(fa,ch);
        } else {
            break;
        }
        fa = ch;
        ch = fa * 2;
    }
}

int main() {
    cin >> n;
    int k = 0;
    
    while(n -- ){
        string oper;
        cin >> oper;
        if(oper == "I") {
            cin >> a;
            ++idx;
            ++k;
            f[idx] = a;
            ph[k] = idx;
            hp[idx] = k;
            push(idx);
        } else if(oper == "PM") {
            cout << f[1] << endl;
        } else if(oper == "DM") {
            heap_swap(1,idx);
            idx--;
            pop(1);
        } else if(oper == "D") {
            cin >> a;
            a = ph[a];
            heap_swap(a,idx);
            idx--;
            pop(a),push(a);
        } else if(oper == "C") {
            cin >> a >> b;
            a = ph[a];
            f[a] = b;
            push(a),pop(a);
        }
    }
    return 0;
}
