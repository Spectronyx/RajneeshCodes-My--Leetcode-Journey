class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n == 0) return 0;
        int cnt = 1;
        int ans = 1;

        for(int i =1;i< n;i++){
            if(arr[i-1] == arr[i]) continue;

            if(arr[i] == arr[i-1]+1){
                cnt++;
            }else{
                cnt = 1;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};