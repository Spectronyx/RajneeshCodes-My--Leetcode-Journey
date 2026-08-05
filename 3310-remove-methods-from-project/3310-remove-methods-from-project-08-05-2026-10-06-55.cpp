class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj,vector<bool> &suspicious){
        suspicious[node] = true;

        for(int nbr: adj[node]){
            if(!suspicious[nbr]){
                dfs(nbr,adj,suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto e: invocations){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        // finding all suspicious methods
        vector<bool> suspicious(n,false);
        dfs(k,adj,suspicious);

        for(auto &e : invocations){
            int u = e[0];
            int v = e[1];

            if(!suspicious[u] && suspicious[v]){
                vector<int> ans;

                for(int i = 0;i < n;i++){
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;
        for(int i = 0;i < n;i++){
            if(!suspicious[i]){
                ans.push_back(i);
            }
        }

        return ans;

    }
};