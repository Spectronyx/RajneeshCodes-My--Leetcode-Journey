class Solution {
public:
    // int maxDepth(string s) {
    
    // }

    // appraoch 1
    int maxDepth(string s) {
        stack<char> st;
        int res = 0;

        for(char ch: s){
            if(ch=='('){
                st.push(ch);
            }else if(ch == ')'){
                st.pop();
            }
            res = max((int)st.size(),res);
        }
        return res;
    }
};