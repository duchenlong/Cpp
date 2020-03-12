#include <iostream>
using namespace std;

int main()
{
	int n,m;//苹果的数量，淘淘伸手可以碰到的高度
	cin>>n>>m; 
	m += 30;//淘淘最大可以碰到的高度 
	
	int ans = n;
	for(int i = 0; i < n; i++)
	{
		int height;//苹果的高度
		cin>>height;
		//如果高度小于最大高度，淘淘可以摘掉，摘不到的苹果数-1 
		if(height <= m)
			ans--; 
	}
	
	cout<<ans<<endl; 
	return 0;
} 
