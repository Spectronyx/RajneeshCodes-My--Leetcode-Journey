class Solution {
public:
    int countSentence(string &s){
        int count = 0;
        bool inWord = false;

        for(char ch: s){
            if(ch != ' '){
                if(!inWord){
                    count++;
                    inWord = true;
                }
            }else{
                    inWord = false;
                }
        }
        return count;
    }
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;
        int n = sentences.size();

        for(int i = 0;i < n;i++){
            maxWords = max(maxWords,countSentence(sentences[i]));
        }
        return maxWords;
    }
};