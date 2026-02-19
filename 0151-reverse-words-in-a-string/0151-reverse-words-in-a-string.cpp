class Solution {
public:
    // string reverseWords(string s) {
    //     int n = s.size();

    //     vector<string> words;

    //     string word = "";

    //     //traverse the string character by character 
    //     for(char ch: s){
    //         if(ch != ' '){
    //             word += ch;
    //         }
    //         else if(!word.empty()){
    //             words.push_back(word);
    //             word = "";
    //         }
    //     }

    //     //push the last word
    //     if(!word.empty()){
    //         words.push_back(word);
    //     }
    //     reverse(words.begin(),words.end());

    //     string ans = "";
    //     for(int i =0;i < words.size();i++){
    //         ans += words[i];

    //         if(i < words.size()-1){
    //             ans+=" ";
    //         }
    //     }
    //     return ans;
    // }

    string reverseWords(string s){
        string result = "";

        //start searching from the end
        int i = s.size()-1;

        //traverse from right to left
        while(i >= 0){
            //skipping the current character and the spaces
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            if(i < 0) break;
            //marking the end
            int end = i;
            
            //moving left until the space is found
            while(i >= 0 && s[i] != ' '){
                i--;
            }

            //extracting the owlrd
            string word = s.substr(i+1,end-i);

            //add space before appeding the new word if reslt is not empty
            if(!result.empty()){
                result += " ";
            }

            result += word;
        }
        return result;
    }
};