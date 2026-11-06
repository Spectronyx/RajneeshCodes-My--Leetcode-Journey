class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> outdegree(n, 0);

        // Reverse graph
        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();

            for (auto ngbr : graph[i]) {
                adj[ngbr].push_back(i);
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto ngbr : adj[node]) {

                outdegree[ngbr]--;

                if (outdegree[ngbr] == 0)
                    q.push(ngbr);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};