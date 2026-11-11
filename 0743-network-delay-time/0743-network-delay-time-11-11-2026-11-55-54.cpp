class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<pair<int,int>>> adj(n+1);

        for(auto e: times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v,wt});
        }

        vector<int> dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});
        dist[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;

            pq.pop();


            for(auto [ngbr,wt]: adj[node]){
                if(wt+cost < dist[ngbr]){
                    dist[ngbr] = wt+cost;
                    pq.push({dist[ngbr],ngbr});
                }
            }
        }

        int ans = 0;

        for(int i = 1;i <=n;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
    }
};