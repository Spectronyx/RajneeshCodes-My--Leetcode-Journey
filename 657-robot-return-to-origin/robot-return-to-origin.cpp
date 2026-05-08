class Solution {
public:
    bool judgeCircle(string moves) {
        int sum = 0;
        for(auto ch: moves){
            if(ch == 'U'){
                sum += 1;
            }else if(ch == 'D'){
                sum -= 1;
            }else if(ch == 'L'){
                sum += 4;
            }else{
                sum -= 4;
            }
        }
        return sum == 0;
    }
};