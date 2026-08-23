class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.size();
        int leftQsMarks = 0;
        int rightQsMarks = 0;

        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] == '?'){
                if(i < n/2){
                    leftQsMarks++;
                }else{
                    rightQsMarks++;
                }
            }else{
                if(i < n/2){
                    leftSum += nums[i]-'0';
                }else{
                    rightSum += nums[i]-'0';
                }
            }
        }

        if((leftQsMarks+rightQsMarks)%2 == 1){
            return true;
        }

        int LEFT = 2*leftSum + 9*leftQsMarks;
        int RIGHT = 2*rightSum + 9*rightQsMarks;

        if(LEFT == RIGHT){
            return false;
        }
        return true;    }
};