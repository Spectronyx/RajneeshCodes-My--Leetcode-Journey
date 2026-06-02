class Solution {
public:
    int solve(vector<int>& start1,vector<int> &duration1,vector<int>& start2,vector<int>& duration2){
        int m = start1.size();
        int n = start2.size();

        int finish1 = INT_MAX;

        for(int i = 0;i < m;i++){
            finish1 = min(finish1,start1[i]+duration1[i]);
        }

        int finish2 = INT_MAX;

        for(int i = 0;i < n;i++){
            finish2 = min(finish2,max(start2[i],finish1)+duration2[i]);
        }

        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int lw = solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int wl = solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(lw,wl); 
    }
};