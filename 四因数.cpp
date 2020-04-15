#include <iostream>
#include <vector>
using namespace std; 

int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
        	int eoch = nums[i];
            int ret = 0;//统计当前因子之和
            int num = 0;//因子数量
            for(int j = 1; j < eoch/2; j++)
            {
                if(eoch % j == 0)
                {
                    ret += eoch/j + j;
                    num += 2;
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
