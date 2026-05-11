// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
    
//         for(auto ch: s){
//             if(ch == '(' || ch == '{' || ch == '['){
//                 st.push(ch);
//             }else{
//                 if(st.empty()) return false;

//                 char top = st.top();

//                 if(top == '(' && ch == ')'||
//                     top == '{' && ch == '}'||
//                     top == '[' && ch == ']'){
//                         st.pop();
//                     }else{
//                         return false;
//                     }
//             }      
//         }
//         return st.empty();
//     }
// };

class Solution{
public:
    bool isValid(string s){
        stack<int> st;

        for(auto ch: s){
            if(ch == '['){
                st.push(']');
            }else if(ch == '{'){
                st.push('}');
            }else if(ch == '('){
                st.push(')');
            }else{
                // ya to stack empty haai ya fir top match match nahiarta

                if (st.empty() || st.top() != ch ){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    
};