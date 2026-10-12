class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        auto cmp = [](pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
        };

        if(nums.size() < k) return {};

        for(auto num: nums){
            mp[num]++;
        }

        priority_queue<pair<int,int> ,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        for(auto &p: mp){
            pq.push(p);

            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){
            auto top = pq.top();
            ans.push_back(top.first);
            pq.pop();
        }

        return ans;
        
    }
};