class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // Goal check: value 0 mil gaya?
            if(arr[curr] == 0) {
                return true;
            }
            
            // Right jump: i + arr[i]
            int right = curr + arr[curr];
            if(right < n && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }
            
            // Left jump: i - arr[i]
            int left = curr - arr[curr];
            if(left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
        }
        
        return false;  // Kabhi 0 tak nahi pahuche
    }
};