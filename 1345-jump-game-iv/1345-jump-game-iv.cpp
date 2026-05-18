class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // If there is only one element, we're already at the destination.
        // Humanity spent decades building computers to discover that staying
        // where you are sometimes solves the problem.
        if (n == 1) return 0;

        vector<bool> visited(n, false);
        queue<int> q;
        unordered_map<int, vector<int>> mp;

        // Store all indices having the same value.
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // Queue should store indices, not values.
        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curr = q.front();
                q.pop();

                // Reached the last index.
                if (curr == n - 1) {
                    return steps;
                }

                int left = curr - 1;
                int right = curr + 1;

                // Move to the left index.
                if (left >= 0 && !visited[left]) {
                    q.push(left);
                    visited[left] = true;   // Mark visited, not false. Chaos has limits.
                }

                // Move to the right index.
                if (right < n && !visited[right]) {
                    q.push(right);
                    visited[right] = true;
                }

                // Jump to all indices having the same value.
                for (int &idx : mp[arr[curr]]) {
                    if (!visited[idx]) {
                        q.push(idx);
                        visited[idx] = true;
                    }
                }

                // Remove this value from the map so we don't process the same
                // group repeatedly and turn BFS into a slow-motion tragedy.
                mp.erase(arr[curr]);
            }

            steps++;
        }

        return -1;  // Theoretically unreachable, but computers enjoy closure.
    }
};