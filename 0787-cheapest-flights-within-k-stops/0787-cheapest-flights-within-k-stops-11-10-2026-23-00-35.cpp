class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int price = f[2];

            adj[u].push_back({v, price});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int, pair<int,int>>> q;

        // {stops, {node, cost}}
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {

            auto [stops, info] = q.front();
            q.pop();

            int node = info.first;
            int cost = info.second;

            if (stops > k)
                continue;

            for (auto [ngbr, price] : adj[node]) {

                int newCost = cost + price;

                if (newCost < dist[ngbr]) {

                    dist[ngbr] = newCost;

                    q.push({
                        stops + 1,
                        {ngbr, newCost}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};