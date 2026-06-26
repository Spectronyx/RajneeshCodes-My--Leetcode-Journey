// class Solution {
// public:
//     bool isMajority(vector<int> &nums,int target,int i,int j){
//         int count = 0;
//         int len = j-i+1;
//         for(int start = i; start <= j;start++){
//             if(nums[start] == target){
//                 count++;
//             }
//         }
//         if(2*count > len){
//             return true;
//         }
//         return false;
//     }
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int count = 0;

//         for(int i = 0;i < n;i++){
//             for(int j = i;j< n;j++){
//                 if(isMajority(nums,target,i,j)){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


// //optimsint the brute force
// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target){
//         int n = nums.size();
//         // pehle step me sabko 1 ya -1 kar do
//         for(int i = 0;i < n;i++){
//             nums[i] = (nums[i] == target) ? 1: -1;
//         }

//         // prefix sum banao
//         vector<int> prefixSum(n+1,0);
//         for(int i = 1;i <= n;i++){
//             prefixSum[i] = prefixSum[i-1]+nums[i-1];
//         }

//         // prev prefix sum ko store karo
//         vector<int> prev;
//         long long ans = 0;

//         for(auto x: prefixSum){
//             int cnt = 0;

//             for(auto y: prev){
//                 if(x > y){
//                     cnt++;
//                 }
//             }
//             ans+= cnt;
//             prev.push_back(x);
//         }
//         return (int)ans;
//     }
// };

class Solution {
public:
    // Fenwick Tree for prefix sum queries
    class Fenwick {
        vector<int> bit;
        int n;
    public:
        Fenwick(int n) : n(n), bit(n + 2, 0) {}
        
        void update(int idx, int val) {
            idx++; // 1-based indexing
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }
        
        int query(int idx) {
            idx++; // 1-based indexing
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };
    
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Convert array: target -> 1, others -> -1
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] == target) ? 1 : -1;
        }
        
        // Build prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        // Coordinate compression for prefix sums
        vector<int> sorted = prefix;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        // Compress each prefix sum to its rank
        vector<int> compressed(n + 1);
        for (int i = 0; i <= n; i++) {
            compressed[i] = lower_bound(sorted.begin(), sorted.end(), prefix[i]) - sorted.begin();
        }
        
        // Fenwick tree to count previous prefix sums
        Fenwick ft(sorted.size());
        long long ans = 0;
        
        // For each prefix sum x, count how many previous y < x
        for (int i = 0; i <= n; i++) {
            // Count previous elements with value < compressed[i]
            int cnt = ft.query(compressed[i] - 1);
            ans += cnt;
            
            // Add current prefix sum to BIT
            ft.update(compressed[i], 1);
        }
        
        return ans;
    }
};