class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerLast(26,-1);
        vector<int> upperFirst(26,-1);
        int count = 0;

        for(int i = 0;i < word.size();i++){
            char ch = word[i];
            if(word[i] <= 'z' && word[i] >= 'a'){
                lowerLast[ch - 'a' ] = i;
            }else{
                int idx = ch -'A';

                if(upperFirst[idx] == -1){
                    upperFirst[idx] = i;
                }
            }
        }

        for(int i = 0;i < 26;i++){
            if(upperFirst[i] != -1 && lowerLast[i] != -1 && lowerLast[i] < upperFirst[i])
                count++;
        }

        return count;
    }
};