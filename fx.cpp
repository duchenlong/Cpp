#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MOD 1000000007

char A[500] = {0};
char B[500] = {0};
int dp[205][100000] = {0}; 
int my_pow[500] = {1,0};

//字符串+1 
void my_add(char* str)
{
	int len = strlen(str);
	int num = 1;
	int i = 0;
	while(num && i < len)
	{

		num += str[i] - '0';
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	
	if(num)
	{
		str[i++] = '1';
	}
	
}

//计算fx权值比重 
int fx(char* str)
{
	int len = strlen(str);
	int num = 0;
	for(int i = len-1; i >= 0; i--)
	{
		num += (str[i] - '0') * my_pow[i] % MOD;
	}
	//cout<<num<<endl;
	return num;
}

//字符数组逆置 
void reverse(char* str)
{
	int len = strlen(str);
	for(int i = 0; i < len / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = tmp;
	}
}

//比较两字符串大小 
int my_strcmp(char* str,char* src,int len)
{
	int flag = 0;
	for(int i = 0; i < len; i++)
	{
		//原串小于目标串 
		if(str[i] < src[i])
			return -1;
		else if(str[i] > src[i])
			flag = 1;
	}
	//大于 
	if(flag)
		return 1;
	//等于 
	return 0;
}

int dfs(int len,int fa,int limit)
{
	if(fa < 0)
		return 0;
	
	if(len <= 0)
		return 1;
	
	if(limit == 0 && dp[len][fa] != -1)
		return dp[len][fa];
	
	int end = limit ? (B[len]-'0') : 9;
	int ret = 0;
	
	for(int i = 0; i <= end; i++)
	{
		ret += dfs(len-1,fa - i * (1<<(len-1)),limit&&(i==end)) % MOD;
		ret %= MOD;
	}
		
	
	if(limit == 0)
		dp[len][fa] = ret;
	
	return ret;
}

int slove()
{
	//逆置A数组
	reverse(A);
	reverse(B);
	for(int i = strlen(B); i > 0; i--)
	{
		B[i] = B[i-1];
	}
	B[0] = '0';
	int fx_A = fx(A);
	memset(dp,-1,sizeof(dp)); 
	int ans = dfs(strlen(B)-1,fx_A,1);
//	char str[500] = {'\0'};
//	int lenb = strlen(B);
//	while(strlen(str) < lenb || my_strcmp(str,B,lenb) < 1)
//	{
//		int fx_n = fx(str);
//		//cout<<"fx_n"<<fx_n<<endl;
//		if(fx_n <= fx_A)
//		{
//			cout<<str<<endl;
//			ans++;
//			//cout<<"ans = "<<ans<<endl;
//		}
//		my_add(str);
//	}
	return ans;
}

//2的阶乘数组初始化 
void Init_pow()
{
	int i = 0;
	for(i = 1; i < 205; i++)
	{
		my_pow[i] = my_pow[i-1] * 2 % MOD;
		//cout<<my_pow[i]<<endl;
	}
}

int main()
{
	int num = 0;
	cin>>num;
	int i = 0;
	Init_pow();
	
	while(i != num)
	{
		memset(A,'\0',sizeof(A));
		memset(B,'\0',sizeof(B));
		cin>>A>>B;
		//cout<<A<<' ' << B<<endl;
		cout<<"Case #"<<i+1<<": "<<slove()<<endl;
		i++;
	}
	
	return 0;
} 
