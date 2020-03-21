//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#include <iostream>
using namespace std;

class ans{
public:
    ans()
    {
        _count++;
        _num += _count;
        
    }
    static void Init()
    {
        _num = 0;
        _count = 0;
    }
    static int GetAns()
    {
        return _num;
    }
private:
    static int _num;
    static int _count;
};

int ans::_num = 0;
int ans::_count = 0;

class Solution {
public:
    //递归
    int Sum_Solution1(int n) {
        int sum = n;
        bool a = n && (sum += Sum_Solution(n-1));
        return sum;
    }
    int Sum_Solution(int n) {
        ans::Init();
        ans *p = new ans[n];
        delete []p;
        p = nullptr;
        return ans::GetAns();
    }
    
    int Sum_Solution2(int n) {
        ans::Init();
        ans a[n];
        return ans::GetAns();
    }
    
    int Sum_Solution3(int n) {
        bool arr[n][n+1];
        return sizeof(arr) >> 1;
    }
};

int main()
{
	int n = 5;
	Solution a;
	a.Sum_Solution(n);
	
	return 0;
}
