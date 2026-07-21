class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = '1'+s+'1';

        int totalOneCount = 0;

        for(char ch: s){
            if(ch == '1'){
                totalOneCount++;
            }
        }

        totalOneCount -= 2; // jo extra do jode

        vector<pair<char,int>> blocks;

        char curr = s[0];
        int len = 1;

        for(int i = 1;i < s.size();i++){
            if(s[i] == curr){
                len++;
            }else{
                blocks.push_back({curr,len});

                curr = s[i];
                len = 1;
            }
        }

        blocks.push_back({curr,len});

        int maxGain = 0;
        // har 1-block ko checkkaro

        for(int i = 1; i+1 < blocks.size();i++){
            if(blocks[i].first == '1' && blocks[i-1].first == '0' && blocks[i+1].first == '0' ){
                int gain = blocks[i+1].second + blocks[i-1].second;

                maxGain = max(gain,maxGain);
            }
        }

        return maxGain + totalOneCount;
    }
};