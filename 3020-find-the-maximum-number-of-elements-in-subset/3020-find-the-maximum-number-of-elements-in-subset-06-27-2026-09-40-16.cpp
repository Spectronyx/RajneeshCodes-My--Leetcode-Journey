class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // unordered map bana lo
        unordered_map<long long ,int> freq;

        for(auto num: nums){
            freq[num]++;
        }

        // 1 ka special case handle kar lo
        int ans = 1;

        if(freq.count(1)){
            int cnt = freq[1];
            ans = max(ans,cnt%2?cnt :cnt-1);
        }

        for(auto &[x,c] : freq){
            if(x == 1) continue;

            long long curr = x;
            int len = 0;

            while(freq.count(curr) && freq[curr] >= 2){
                len += 2;
                curr = curr*curr;

                if(curr > 1e18){
                    break;
                }

            }

            // for the center element
            if(freq.count(curr)){
                len++;
            }
            else len--;

            ans = max(ans,len);
        }
        return ans;
    }
};