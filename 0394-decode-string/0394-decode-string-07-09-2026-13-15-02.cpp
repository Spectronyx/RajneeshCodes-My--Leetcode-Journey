class Solution {
public:
    string decodeString(string s) {

        stack<pair<string,int>> st;

        string currString = "";
        int currNumber = 0;

        for(char ch : s){

            if(isdigit(ch)){

                currNumber = currNumber * 10 + (ch - '0');
            }

            else if(ch == '['){

                st.push({currString, currNumber});

                currString = "";
                currNumber = 0;
            }

            else if(ch == ']'){

                auto top = st.top();
                st.pop();

                string prevString = top.first;
                int repeat = top.second;

                string decoded = "";

                while(repeat--){
                    decoded += currString;
                }

                currString = prevString + decoded;
            }

            else{

                currString += ch;
            }
        }

        return currString;
    }
};