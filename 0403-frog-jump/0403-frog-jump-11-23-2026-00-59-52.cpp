class Solution {
public:
    int n;
    int dp[2001][2001];
    unordered_map<int,int> mp;
    bool solve(vector<int> &stones,int current_index,int prevJump){
        if(current_index == n-1) return true;

        if(dp[current_index][prevJump] != -1) return dp[current_index][prevJump];

        bool result = false;

        for(int nextJump = prevJump-1;nextJump <= prevJump+1;nextJump++){
          if(nextJump>0){
            int nextStone = stones[current_index]+nextJump;
            if(mp.find(nextStone)!= mp.end()){
                result = result || solve(stones,mp[nextStone],nextJump);
            }
          }  
        }

        return dp[current_index][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(dp,-1,sizeof(dp));

        if(stones[1] != 1) return false;
        
        for(int i = 0;i < n;i++){
            mp[stones[i]] = i;
        }
        return solve(stones,0,0);
    }
};