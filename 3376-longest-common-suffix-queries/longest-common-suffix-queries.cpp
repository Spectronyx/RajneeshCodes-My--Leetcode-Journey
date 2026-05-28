class Solution {
public:

    struct Node {
        int child[26];
        int idx;
        int len;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
            len = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node()); // root
    }

    void insert(string &word, int id) {

        int node = 0;
        int n = word.size();

        // update root info
        if(trie[node].len > n) {
            trie[node].len = n;
            trie[node].idx = id;
        }

        for(int i = n - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if(trie[node].len > n) {
                trie[node].len = n;
                trie[node].idx = id;
            }
        }
    }

    int search(string &word) {

        int node = 0;
        int ans = trie[node].idx;

        for(int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                return ans;
            }

            node = trie[node].child[c];
            ans = trie[node].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsContainer.size();
        int m = wordsQuery.size();

        for(int i = 0; i < n; i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++) {
            ans[i] = search(wordsQuery[i]);
        }

        return ans;
    }
};