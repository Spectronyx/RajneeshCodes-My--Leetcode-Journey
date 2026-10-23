
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if (!root) return;

        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left, adj);
        }

        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right, adj);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;

        unordered_map<int, vector<int>> adj;
        dfs(root, adj);

        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int minutes = 0;

        while (!q.empty()) {
            int size = q.size();

            // Kya is level par naye nodes infect hue?
            bool spread = false;

            while (size--) {
                int front = q.front();
                q.pop();

                for (int nbr : adj[front]) {
                    if (!visited.count(nbr)) {
                        q.push(nbr);
                        visited.insert(nbr);
                        spread = true;
                    }
                }
            }

            // Ek level ka spread ek minute leta hai
            if (spread) minutes++;
        }

        return minutes;
    }
};
