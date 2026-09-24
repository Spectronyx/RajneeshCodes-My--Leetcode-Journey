class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        for(int i = 0;i < n;i++){

            vector<int>& last = ans.back();
            int lastStart = last[0];
            int lastEnd = last[1];

            int currentFirst = intervals[i][0];
            int currentLast = intervals[i][1];

            if(currentFirst <= lastEnd){
                last[1] = max(currentLast,lastEnd);
            }else{
                ans.push_back(intervals[i]);
            }
            
        }
        return ans;
    }
};