#include <iostream>
using namespace std;

//递归 
int fun(int n,int num)
{
	if(n == 1)
		return num;
	
	return fun(n-1,(num+1) * 2);
}

//递推
int GetNumber(int n)
{
	int num = 1;
	for(int i = n; i > 1; i--)
	{
		num = (num + 1) * 2;
	}
	return num;
}



 
int main()
{
	int n;//到第n天只剩下一个桃子
	cin>>n;
	
	cout<<GetNumber(n)<<endl;
	
	return 0; 
} 
