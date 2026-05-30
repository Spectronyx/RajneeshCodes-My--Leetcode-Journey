class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;

        for (auto &q : queries) {
            mx = max(mx, q[1]);
        }

        SegmentTree seg(mx + 1);

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        int prev = 0;

        for (int pos : obstacles) {
            if (pos == 0) continue;

            seg.update(pos, pos - prev);
            prev = pos;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = std::prev(obstacles.upper_bound(x));
                int lastObstacle = *it;

                int bestGap = seg.query(0, x);

                ans.push_back(
                    max(bestGap, x - lastObstacle) >= sz
                );
            }
            else {
                int x = q[1];

                auto it = obstacles.find(x);

                auto prv = std::prev(it);
                auto nxt = std::next(it);

                if (nxt != obstacles.end()) {
                    seg.update(*nxt, *nxt - *prv);
                }

                seg.update(x, 0);
                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};