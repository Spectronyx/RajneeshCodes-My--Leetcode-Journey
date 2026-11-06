class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        queue<int> q;
        int cnt = 0;

        for(auto e: prerequisites){
            int u = e[0];
            int v = e[1];

            adj[v].push_back(u);
            indegree[u]++;
        }


        for(int i = 0;i < numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;


            for(auto &ngbr: adj[node]){
                indegree[ngbr]--;

                if(indegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }

        return cnt == numCourses;
    }
};