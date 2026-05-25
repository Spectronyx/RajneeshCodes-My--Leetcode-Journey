class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int n = s.size();
        int farthest = 0;

        q.push(0);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int i = max(front+minJump,farthest+1);i <= min(front+maxJump,n-1);i++){
                if(s[i] == '0'){
                    q.push(i);

                    if(i == s.size() -1) return true;
                }
            }

            farthest = max(front+maxJump,farthest);
        }
        return false;
    }
};