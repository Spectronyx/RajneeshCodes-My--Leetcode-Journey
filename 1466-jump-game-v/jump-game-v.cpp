class Solution {
public:
    int dfs(vector<int> &arr,int d,int i,vector<int> &dp){
        if(dp[i] != -1) return dp[i];

        int n = arr.size();
        int maxJumps = 1;

        //try left jump;
        for(int j = i-1;j >= max(0,i-d) && arr[j] < arr[i];j--){
            maxJumps = max(maxJumps,1+dfs(arr,d,j,dp));
        }

        for(int j = i+1; j<= min(i+d,n-1) && arr[j] < arr[i];j++){
            maxJumps = max(maxJumps,1+dfs(arr,d,j,dp));
        }

        return dp[i] = maxJumps;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        vector<int> dp(n,-1);

        int maxVisits = 0;

        for(int i = 0;i < n;i++){
            maxVisits = max(maxVisits,dfs(arr,d,i,dp));
        }

        return maxVisits;
    }
};