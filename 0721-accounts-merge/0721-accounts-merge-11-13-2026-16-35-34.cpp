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

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Step 1: Compare every pair of accounts
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                bool common = false;

                // Compare emails
                for (int x = 1; x < accounts[i].size(); x++) {
                    for (int y = 1; y < accounts[j].size(); y++) {

                        if (accounts[i][x] == accounts[j][y]) {
                            common = true;
                            break;
                        }
                    }

                    if (common) break;
                }

                if (common) {
                    Union(i, j);
                }
            }
        }

        // Step 2: Group emails by component
        unordered_map<int, set<string>> groups;

        for (int i = 0; i < n; i++) {
            int p = find(i);

            for (int j = 1; j < accounts[i].size(); j++) {
                groups[p].insert(accounts[i][j]);
            }
        }

        // Step 3: Construct answer
        vector<vector<string>> ans;

        for (auto& it : groups) {
            int p = it.first;

            vector<string> temp;
            temp.push_back(accounts[p][0]);

            for (auto& email : it.second) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};