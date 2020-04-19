由 n 个连接的字符串 s 组成字符串 S，记作?S = [s,n]。例如，["abc",3]=“abcabcabc”。

如果我们可以从 s2?中删除某些字符使其变为 s1，则称字符串 s1?可以从字符串 s2 获得。例如，根据定义，"abc" 可以从 “abdbec” 获得，但不能从 “acbbe” 获得。

现在给你两个非空字符串 s1?和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 106?和 1 ≤ n2 ≤ 106。现在考虑字符串 S1 和 S2，其中 S1=[s1,n1]?、S2=[s2,n2] 。

请你找出一个可以满足使[S2,M] 从 S1?获得的最大整数 M 。

?

示例：

输入：
s1 ="acb",n1 = 4
s2 ="ab",n2 = 2

返回：
2



class Solution {
public:
	//超时。。。。。。。 
    int getMaxRepetitions1(string s1, int n1, string s2, int n2) {
        int counts1 = 0, counts2 = 0;
        int lens1 = s1.size(), lens2 = s2.size();
        int s1i = 0, s2i = 0;

        while(counts1 < n1){
            for(int i = 0; i < lens1; i++){
                //如果两个字符相同，s2i后移一位
                if(s1[i] == s2[s2i]){
                    s2i++;
                    //s2串已经遍历万的情况，回退到开头
                    if(s2i == lens2){
                        counts2++;
                        s2i = 0;
                    }
                }
                
            }
            counts1++;//s1肯定遍历一次结束了

            if(s2i == 0){
                double nums = n1 / counts1;
                counts1 = counts1 * nums;
                counts2 = counts2 * nums;
            }
        }

        return counts2 / n2;
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2){
        int lens2 = s2.size(), lens1 = s1.size();
        vector<int> retarr(lens2,0);//以s2中每一个字符开头，可以在s1中重复多少次
        vector<int> nextarr(lens2,0);//以s2中这个字符开头，在s1中重复后最后一个出现的字符的索引

        for(int i = 0; i < lens2; i++){
            int ret = 0;
            int next = i;

            for(int j = 0; j < lens1; j++){
                if(s1[j] == s2[next]){
                    next++;
                    if(next == lens2){
                        next = 0;
                        ret++;
                    }
                }
            }

            retarr[i] = ret;
            nextarr[i] = next;
        }
        
        int ret = 0, next = 0;
        for(int i = 0; i < n1; i++)
        {
            ret += retarr[next];
            next = nextarr[next];
        }

        return ret / n2;
    }
};
