class Solution {
public:
    int digitSum(int n){
        int sum = 0;

        while(n){
            int ld = n%10;
            sum += ld;
            n/=10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int dSum = 0;
        for(auto num: nums){
            sum += num;
            dSum += digitSum(num);
        }

        return abs(dSum-sum);
    }
};