//实现一个 Trie (前缀树)，包含?insert,?search, 和?startsWith?这三个操作。

//示例:

//Trie trie = new Trie();

//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");   
//trie.search("app");     // 返回 true
//说明:

//你可以假设所有的输入都是由小写字母?a-z?构成的。
//保证所有输入均为非空字符串。



class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        idx = 0;
        memset(son,0,sizeof(son));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int u = word[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int u = word[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
            if(key[p] == word) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for(int i = 0; i < prefix.size(); i++)
        {
            int u = prefix[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }

private:
    const static int N = 100000;
    int son[N][26];
    int idx;
    string key[N];
};
