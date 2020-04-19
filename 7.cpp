#include <iostream>
using namespace std;

int arr[1005][1005] = {0};

int main()
{
	int n,m;
	cin>>n>>m;
	int r,c;
	cin>>r>>c;
	
	int i = 1, j = 1;
	int num = 1;
	int left = 1, right = m, up = 2, down = n;
	while(num <= n*m)
	{
		//right
		for(; j <= right; j++)
		{
			arr[i][j] = num;
			num++;
		}
		right--;
		j--;
		i++;
		
		//dowm
		for(; i <= down; i++)
		{
			arr[i][j] = num;
			num++;
		}
		down--;
		i--;
		j--;
		
		//left
		for(; j >= left; j--)
		{
			arr[i][j] = num;
			num++;
		}
		left++;
		j++;
		i--;
		
		//up
		for(; i >= up; i--)
		{
			arr[i][j] = num;
			num++;
		}
		up++;
		i++;
		j++;
	}
	cout<<arr[r][c]<<endl;
	
	//for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		{
//			cout<<arr[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}
