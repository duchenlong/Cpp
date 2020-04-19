#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[200] = {'\0'};
	cin>>str;
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		str[i] = 'a' + (str[i] - 'a' + 3) % 26;
	}
	cout<<str<<endl;
	return 0;
}
