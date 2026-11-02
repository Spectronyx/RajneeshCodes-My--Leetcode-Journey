class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);

        for(int i = 0;i < graph.size();i++){
            if(colors[i] != -1) continue;

            queue<int> q;
            q.push(i);
            colors[i] = 0;

            while(!q.empty()){
                int front = q.front();
                q.pop();


                for(auto ngbr: graph[front]){
                    if(colors[ngbr] == -1 ){
                        colors[ngbr] = 1-colors[front];
                        q.push(ngbr);
                    }else if(colors[ngbr] == colors[front]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};