class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);

        for(auto i = 0;i < graph.size();i++){
            // if the vertex is alreadly colored skip it
            if(colors[i] != -1) continue;

            queue<int> q;
            q.push(i);
            colors[i] = 0;

            while(!q.empty()){
                int top = q.front();
                q.pop();

                for(auto nbr: graph[top]){
                    //if neibor not colored
                    if(colors[nbr] == -1){
                        colors[nbr] = 1-colors[top];
                        q.push(nbr);
                    }else if(colors[nbr] == colors[top]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};