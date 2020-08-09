请你设计一个迭代器类，包括以下内容：

一个构造函数，输入参数包括：一个?有序且字符唯一?的字符串?characters（该字符串只包含小写英文字母）和一个数字?combinationLength?。
函数?next()?，按?字典序?返回长度为?combinationLength 的下一个字母组合。
函数?hasNext()?，只有存在长度为?combinationLength 的下一个字母组合时，才返回?True；否则，返回 False。
?

示例：

CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator

iterator.next(); // 返回 "ab"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "ac"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "bc"
iterator.hasNext(); // 返回 false
?

提示：

1 <= combinationLength <=?characters.length <= 15
每组测试数据最多包含?10^4?次函数调用。
题目保证每次调用函数?next?时都存在下一个字母组合。


class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        len = combinationLength;
        dfs("",0,0,len);
        index = 0;
    }
    
    string next() {
        return ans[index++];
    }
    
    bool hasNext() {
        return index != ans.size();
    }
private:
    void dfs(string s,int idx,int size,int len)
    {
        if(size == len)
        {
            ans.push_back(s);
            return ;
        }

        for(int i = idx; i <= str.size() - len + size; i++)
            dfs(s + str[i],i+1,size+1,len);
    }
private:
    vector<string> ans;
    string str;
    int len;
    int index;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
