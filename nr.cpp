#include <iostream>
using namespace std;

char arr[10] = {0};

int fun(int n,int r)
{
//	if(r == 1)
//	{
//		for(int i = 1; i <= n; i++)
//		{
//			arr[r-1] = i + '0';
//			
//		}
//		return n;
//	}
	if(r == 0)
		return 1;
	
	int ans = 0;
	for(int i = n; i >= r; i--)
	{
		arr[r-1] = i + '0';
		if(r == 1)
			cout<<arr<<endl;
		ans += fun(i-1,r-1);
	}
	
	return ans;
}

int main()
{
	int n,r;
	cin>>n>>r;
	
	int ans = fun(n,r);
	
	cout<<ans<<endl;
	
	return 0;
} 
