//请你实现一个「数字乘积类」ProductOfNumbers，要求支持下述两种方法：

//1.?add(int num)

//将数字?num?添加到当前数字列表的最后面。
//2. getProduct(int k)

//返回当前数字列表中，最后?k?个数字的乘积。
//你可以假设当前列表中始终 至少 包含 k 个数字。
//题目数据保证：任何时候，任一连续数字序列的乘积都在 32-bit 整数范围内，不会溢出。

//?

//示例：

//输入：
//["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
//[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

//输出：
//[null,null,null,null,null,null,20,40,0,null,32]

//解释：
//ProductOfNumbers productOfNumbers = new ProductOfNumbers();
//productOfNumbers.add(3);        // [3]
//productOfNumbers.add(0);        // [3,0]
//productOfNumbers.add(2);        // [3,0,2]
//productOfNumbers.add(5);        // [3,0,2,5]
//productOfNumbers.add(4);        // [3,0,2,5,4]
//productOfNumbers.getProduct(2); // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
//productOfNumbers.getProduct(3); // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
//productOfNumbers.getProduct(4); // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
//productOfNumbers.add(8);        // [3,0,2,5,4,8]
//productOfNumbers.getProduct(2); // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32 



//超时
class ProductOfNumbers1 {
public:
    ProductOfNumbers1() {
        mul.push_back(0);
    }
    
    void add(int num) {
        for(auto& eoch : mul)
            eoch *= num;
        mul.push_back(num);
    }
    
    int getProduct(int k) {
        return mul[mul.size() - k];
    }
private:
    vector<int> mul;
};

class ProductOfNumbers {
public:
    ProductOfNumbers() {
        mul.push_back(1);
    }
    
    void add(int num) {
        if(num == 0)
        {
            mul = vector<int> (1,1);
            return ;
        }
        mul.push_back(num * mul.back());
    }
    
    int getProduct(int k) {
        if(k >= mul.size()) return 0;
        return mul.back() / mul[mul.size() - k - 1]; 
    }
private:
    vector<int> mul;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
