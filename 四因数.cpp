#include <iostream>
#include <vector>
using namespace std; 

int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto eoch : nums)
        {
            int ret = 0;//统计当前因子之和
            int num = 0;//因子数量
            for(int j = 1; j <= sqrt(eoch); j++)
            {
                int count = eoch / j;
                if( eoch % j == 0)
                {
                    if(count == j)
                    {
                        ret += eoch;
                        num += 1;
                    }
                    else
                    {
                        ret += eoch/j + j;
                        num += 2;
                    }
                    
                }
                if(num > 4)
                    break;
            }
            if(num == 4)
                ans += ret;
        }

        return ans;
    }
    
int main()
{
	vector<int> arr(3);
	arr[0]= 21;
	arr[1]= 4;
	arr[2] = 7;
	cout<<sumFourDivisors(arr)<<endl;
	
	return 0;
}
