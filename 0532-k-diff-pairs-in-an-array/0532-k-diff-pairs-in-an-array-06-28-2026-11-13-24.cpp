class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(auto num: nums){
            freq[num]++;
        }
        int count = 0;
        for(auto p: freq){
            int x = p.first;
            int c = p.second;
            if(k != 0){
                if(freq.find(x+k) != freq.end()){
                    count++;
                }
                // freq.erase(x);
            }else if(k == 0){
                if(c >= 2){
                    count++;
                }
            }
        }
        return count;
    }
};