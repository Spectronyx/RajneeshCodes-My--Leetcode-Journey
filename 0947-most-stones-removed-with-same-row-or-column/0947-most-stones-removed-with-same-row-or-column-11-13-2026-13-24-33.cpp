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
        int N = stones.size();
        parent.resize(N);
        size.assign(N, 1);

        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }

        

        for(int i = 0;i < N;i++){
            for(int j = i+1;j < N;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    Union(i,j);
                }
            }
        }

        int components = 0;

        for (int i = 0;i< N;i++) {
            if (parent[i] == i) {
                components++;
            }
        }

        return stones.size() - components;
    }
};