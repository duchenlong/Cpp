class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for(char ch : S){
            if(!st.empty() && st.top() == ch){
                st.pop();
                continue;
            }
            st.push(ch);
        }

        string ans("");
        ans.resize(st.size());
        while(!st.empty()){
            ans[st.size()-1] = st.top();
            st.pop();
        }

        return ans;
    }
};
