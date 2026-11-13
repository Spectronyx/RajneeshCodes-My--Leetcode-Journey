class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int u,int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        parent[pu]= pv;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // n to no of computers hai;
        // kruskal ka application hai

        if(connections.size() < n-1) return -1;

        parent.resize(n);

        for(int i = 0;i < n;i++){
            parent[i] = i;
        }

        for(auto conn: connections){
            int x = conn[0];
            int y = conn[1];

            if(find(x) != find(y)){
                Union(x,y);
                n--;
            }
        }
        return n-1;
    }
};