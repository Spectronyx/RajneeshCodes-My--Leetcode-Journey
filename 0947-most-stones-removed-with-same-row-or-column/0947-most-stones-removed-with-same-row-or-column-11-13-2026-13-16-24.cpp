class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        }
        else {
            parent[py] = px;
            size[px] += size[py];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int OFFSET = 10001;
        int N = 20002;

        parent.resize(N);
        size.assign(N, 1);

        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }

        unordered_set<int> used;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;

            Union(row, col);

            used.insert(row);
            used.insert(col);
        }

        int components = 0;

        for (int node : used) {
            if (find(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};