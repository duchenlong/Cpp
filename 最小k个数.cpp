//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

// 

//示例 1：

//输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
//示例 2：

//输入：arr = [0,1,2,1], k = 1
//输出：[0]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* arr,int left,int right)
{
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
}

void sort(int* arr, int arrSize, int k,int left,int right)
{
    //快拍结束的条件
    if(left >= right || left >= k)
        return ;
    
    int num = arr[left];
    int l = left;
    int r = right;
    while(l < r)
    {
        //从右向左找
        while(l < r && arr[r] >= num)
            r--;
        arr[l] = arr[r];

        //从左向右找
        while(l < r && arr[l] <= num)
            l++;
        arr[r] = arr[l];
    }
    arr[l] = num;
    //只需要找比k序列号小的
    if(l < k)
        sort(arr,arrSize,k,l+1,right);
    else if(l > k)
        sort(arr,arrSize,k,left,l-1);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    sort(arr,arrSize,k,0,arrSize-1);
    *returnSize = k;
    return arr;
}
