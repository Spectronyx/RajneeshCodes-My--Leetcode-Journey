class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        // int n = edges[0].size();
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> adj;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // find the connected components;
        int components = 0;

        // har ek node par bfs chalao
        for(int i = 0;i< n;i++){
            // agar node visited nahi h to
            if(!visited[i]){
                int nodes = 0;
                long long edgeCount = 0;

                // i ko start node maankar bfs mar do
                queue<int> q;
                q.push(i);
                visited[i] = 1;


                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    nodes++;
                    edgeCount += adj[node].size();

                    for(auto &ngbr: adj[node]){
                        if(!visited[ngbr]){
                            visited[ngbr] = 1;
                            q.push(ngbr);
                        }
                    }
                }

                // every undirected edge counted twice
                edgeCount /= 2;

                long long requiredEdges = 1LL *nodes*(nodes-1)/2;

                if(edgeCount == requiredEdges) components++;
            }
        }
        return components;
    }
};