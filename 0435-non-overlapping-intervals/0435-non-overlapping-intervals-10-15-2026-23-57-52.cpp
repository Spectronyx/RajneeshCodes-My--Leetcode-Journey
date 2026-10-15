class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int ans = 0;

        int lastEnd = intervals[0][1];
        int lastStart = intervals[0][0];

        for(int i = 1;i < n;i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart < lastEnd){
                ans++;
                lastEnd = min(lastEnd,currEnd);
            }else{
                lastEnd = currEnd;
            }

        }

        return ans;
    }
};