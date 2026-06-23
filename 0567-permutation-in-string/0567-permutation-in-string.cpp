class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char ch: s1){
            freq1[ch-'a']++;
        }

        int k = s1.size();

        for(int i = 0;i <k;i++){
            freq2[s2[i]-'a']++;
        }

        if(freq1== freq2) return true;

        for(int right = k;right < s2.size();right++){

            // add new char 
            freq2[s2[right]-'a']++;

            // remove the old char
            freq2[s2[right-k]-'a']--;

            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};