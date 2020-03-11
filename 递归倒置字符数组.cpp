#include <iostream>
using namespace std;

char str[10000] = {'\0'};

void swap(int a,int b)
{
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}

void fun(int start,int len)
{
	if(start == len/2)
		return ;
	
	int left = start;
	int right = len - 1 - start;
	
	swap(left,right);
	cout<<str<<endl;
	fun(start+1,len);
}

int main()
{
	int len;
	
	cin>>len>>str;
	fun(0,len);
	
	cout<<endl<<str;
	return 0;
}
