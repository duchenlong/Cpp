#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,a,b;
string s,res;
string id;
int nums[256];

void slove() {
    res = "";
    vector<int> arr;
    for(int i = s.size() - 1; i >= 0; i--) arr.push_back(nums[s[i]]);
    while(arr.size()) {
        int t = 0; // 进位
        for(int i = s.size() - 1; i >= 0; i--) {
            arr[i] += t * a;
            t = arr[i] % b;
            arr[i] /= b;
        }
        res.push_back(id[t]);
        while(arr.size() && arr.back() == 0) arr.pop_back();
    }
    reverse(res.begin(),res.end());
}

int main() {
    cin >> n;
    for(char i = '0'; i <= '9'; i++) {
        id += i;
        nums[i] = i - '0';
    }
    for(char i = 'A'; i <= 'Z'; i++)  {
        id += i;
        nums[i] = i - 'A' + 10;
    }
    for(char i = 'a'; i <= 'z'; i++)  {
        id += i;
        nums[i] = i - 'a' + 36;
    }
    while(n --) {
        cin >> a >> b >> s;
        slove();
        cout << a << " " << s << endl;
        cout << b << " " << res << endl;
        puts("");
    }
}

编写一个程序，可以实现将一个数字由一个进制转换为另一个进制。

这里有62个不同数位{0-9,A-Z,a-z}。

输入格式
第一行输入一个整数，代表接下来的行数。

接下来每一行都包含三个数字，首先是输入进制（十进制表示），然后是输出进制（十进制表示），最后是用输入进制表示的输入数字，数字之间用空格隔开。

输入进制和输出进制都在2到62的范围之内。

（在十进制下）A = 10，B = 11，…，Z = 35，a = 36，b = 37，…，z = 61 (0-9仍然表示0-9)。

输出格式
对于每一组进制转换，程序的输出都由三行构成。

第一行包含两个数字，首先是输入进制（十进制表示），然后是用输入进制表示的输入数字。

第二行包含两个数字，首先是输出进制（十进制表示），然后是用输出进制表示的输入数字。

第三行为空白行。

同一行内数字用空格隔开。

输入样例：
8
62 2 abcdefghiz
10 16 1234567890123456789012345678901234567890
16 35 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 23 333YMHOUE8JPLT7OX6K9FYCQ8A
23 49 946B9AA02MI37E3D3MMJ4G7BL2F05
49 61 1VbDkSIMJL3JjRgAdlUfcaWj
61 5 dl9MDSWqwHjDnToKcsWE1S
5 10 42104444441001414401221302402201233340311104212022133030
输出样例：
62 abcdefghiz
2 11011100000100010111110010010110011111001001100011010010001

10 1234567890123456789012345678901234567890
16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2

16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 333YMHOUE8JPLT7OX6K9FYCQ8A

35 333YMHOUE8JPLT7OX6K9FYCQ8A
23 946B9AA02MI37E3D3MMJ4G7BL2F05

23 946B9AA02MI37E3D3MMJ4G7BL2F05
49 1VbDkSIMJL3JjRgAdlUfcaWj

49 1VbDkSIMJL3JjRgAdlUfcaWj
61 dl9MDSWqwHjDnToKcsWE1S

61 dl9MDSWqwHjDnToKcsWE1S
5 42104444441001414401221302402201233340311104212022133030

5 42104444441001414401221302402201233340311104212022133030
10 1234567890123456789012345678901234567890
难度：简单
时/空限制：1s / 64MB
总通过数：688
总尝试数：1270
来源：《算法竞赛进阶指南》
算法标签
