class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        sort(points.begin(),points.end(),[](auto &a,auto&b){
            return b[1] > a[1];   
        });

        int lastEnd = points[0][1];

        for(int i = 1;i < n;i++){
            int currStart = points[i][0];
            int currEnd = points[i][1];
            if(currStart > lastEnd){
                ans++;
                lastEnd = currEnd;
            }
        }
        return ans+1;
    }
};