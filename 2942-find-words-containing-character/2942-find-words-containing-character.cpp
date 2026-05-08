class Solution {
public:
    // bool count(string &s,char target){
    //     for(auto ch: s){
    //         if(ch == target){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        // for(int i = 0;i < words.size();i++){
        //     if(count(words[i],x)){
        //         ans.push_back(i);
        //     }
        // }

        for(int i = 0;i < words.size();i++){
            if(words[i].find(x) != string::npos){
                ans.push_back(i);
            }
        }
        return ans;
    }
};