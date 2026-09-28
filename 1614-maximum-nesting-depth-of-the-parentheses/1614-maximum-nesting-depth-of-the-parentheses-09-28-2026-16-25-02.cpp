class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;

        for(auto ch: s){
            if(ch == '('){
                count++;
            }else if(ch == ')'){
                count--;
            }

            maxCount = max(count,maxCount);
        }
        return maxCount;
    }
};