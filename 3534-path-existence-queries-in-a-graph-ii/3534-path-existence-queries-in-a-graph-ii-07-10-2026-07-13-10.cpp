class Solution {
public:
    int getDistance(int u, int v,
                vector<int>& comp,
                vector<vector<int>>& up) {

    if (comp[u] != comp[v])
        return -1;

    if (u > v)
        swap(u, v);

    int ans = 0;

    for (int k = 19; k >= 0; k--) {

        if (up[k][u] < v) {

            ans += (1 << k);

            u = up[k][u];
        }
    }

    return ans + (u != v);
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // sabse pehle sort karke indices store kar do
        vector<pair<int,int>> arr;

        for(int i = 0;i < nums.size();i++){
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        vector<int> pos(n);

        for(int i = 0;i< n;i++){
            pos[arr[i].second] = i;
        }

        vector<int> components(n);
        int id = 0;
        components[0] = 0;

        for(int i = 1;i < n;i++){
            if(arr[i].first - arr[i-1].first > maxDiff){
                id++;
            }
            components[i] = id; 
        }

        //ek jump me maximum kahan tak ja sakte hain
        vector<int> nextPos(n);
        int j = 0;

        for(int i = 0;i < n;i++){
            while(j+1 < n && arr[j+1].first - arr[i].first <= maxDiff){
                j++;
            }
            nextPos[i] = j;
        }

        int LOG = 20;
        vector<vector<int>> up(LOG,vector<int>(n));

        for(int i = 0;i < n;i++){
            up[0][i] = nextPos[i];
        }

        for(int k = 1;k < LOG;k++){
            for(int i = 0;i < n;i++){
                up[k][i] = up[k-1][up[k-1][i]];
            }
        }

        vector<int> ans;

        for(auto q:queries){
            int u = pos[q[0]];
            int v = pos[q[1]];

            ans.push_back(components[u] != components[v] ? -1 : getDistance(u,v,components,up));
        }

        return ans;
    }
};