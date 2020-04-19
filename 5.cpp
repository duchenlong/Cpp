#include <iostream>
using namespace std;

int main()
{
	int ans = 0;
	int n;
	cin>>n;
	int a,b,c;
	cin>>a>>b>>c;
	
	for(int i = 1; i <= n; i++)
	{
		if(i%a && i%b && i%c)
			ans++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
