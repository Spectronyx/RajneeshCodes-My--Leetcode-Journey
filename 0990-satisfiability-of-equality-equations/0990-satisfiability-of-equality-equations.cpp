class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    void Union(int x,int y){
        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y) return;

        if(rank[p_x] > rank[p_y]){
            parent[p_y] = p_x;
        }else if(rank[p_y] > rank[p_x]){
            parent[p_x] = p_y;
        }else{
            parent[p_x] = p_y;
            rank[p_y]++;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);


        for(int i = 0;i < 26;i++){
            parent[i] = i;
        }

        // doing uinion
        for(string &s : equations){
            if(s[1] == '='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        // chekci8ng validity
        for(string &s : equations){
            if(s[1] =='!'){
                int first = find(s[0]-'a');
                int second = find(s[3]-'a');


                int first_parent = find(first);
                int second_parent = find(second);

                if(first_parent == second_parent) return false;
            }
        }
        return true;
    }
};