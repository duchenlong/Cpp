#include <iostream>
#include <string>
#include <vector>
using namespace std;

string id[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    string s;
    cin >> s;
    int num = 0;
    for(auto& e : s) 
        num += e - '0';
    
    if(num == 0) {
        cout << id[0];
        return 0;
    }
    
    vector<string> res;
    while(num) {
        res.push_back(id[num % 10]);
        num /= 10;
    }
    for(int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] << " ";
    return 0;
}


给定一个非负整数 N，你的任务是计算 N 的所有数字的总和，并以英语输出总和的每个数字。

输入格式
共一行，包含一个整数 N。

输出格式
共一行，用英语输出总和的每个数字，单词之间用空格隔开。

数据范围
0≤N≤10100
输入样例：
12345
输出样例：
one five
