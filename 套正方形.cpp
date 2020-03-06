#include <iostream>
#include <string.h>
using namespace std;

int arr[55][55] = {0};

int main()
{
	int width;
	cin>>width;
	
	int left = 0;
	int right = width-1;
	for(int i = 1; i < width; i++)
	{
		memcpy(arr[i],arr[i-1],sizeof(int) * width);
		for(int j = left + 1; j < right; j++)
			arr[i][j] = !arr[i][j];
		
		left += 1;
		right -= 1;
	}
	
	for(int i = 0; i < width/2; i++)
	{
		for(int j = 0; j < width; j++)
			if(arr[i][j])
				cout<<' ';
			else
				cout<<'*';
		
		cout<<endl;
	}
	
	for(int i = width/2-1; i >= 0; i--)
	{
		for(int j = 0; j < width; j++)
			if(arr[i][j])
				cout<<' ';
			else
				cout<<'*';
		
		cout<<endl;
	}
	return 0;
}
