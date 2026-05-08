class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;

        int n = accounts.length;
        int m = accounts[0].length;

        for(int i = 0;i < n;i++){
            int wealth = 0;
            for(int j = 0;j< m;j++){
                wealth += accounts[i][j];
            }
            maxWealth = Math.max(maxWealth,wealth);    
        }

        return maxWealth;
    }
}