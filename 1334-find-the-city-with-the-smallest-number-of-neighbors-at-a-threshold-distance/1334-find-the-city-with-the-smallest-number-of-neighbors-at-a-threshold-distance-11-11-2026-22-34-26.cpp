class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n,vector<int>(n,INF));

        // diagonal ko zero mark kar do
        for(int i = 0;i < n;i++){
            dist[i][i] = 0;
        }

        // graph bana lo;
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }


        // floyed warshall 
        for(int via = 0;via < n;via++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(dist[i][via] != INF && dist[via][j] != INF){
                        dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                    }
                }
            }
        }

        // cities count karte hai jo reachable hai
        int minCount = INT_MAX;
        int ans = -1;

        for(int i =0;i < n;i++){
            int count = 0;
            for(int j =0;j < n;j++){
                if(i != j && dist[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= minCount){
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};