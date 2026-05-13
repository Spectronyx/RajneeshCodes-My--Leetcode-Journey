class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(num.size() == k) return "0";
        for(char digit: num){
            while(!st.empty() && k > 0 && st.top() > digit){
                st.pop();
                k--;
            }

            if(st.size() > 0 || digit != '0'){
                st.push(digit);
            }
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};