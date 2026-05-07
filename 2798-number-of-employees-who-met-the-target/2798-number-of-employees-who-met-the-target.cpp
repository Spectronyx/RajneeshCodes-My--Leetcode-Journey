class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(auto h: hours){
            if(h >= target){
                count++;
            }
        }
        return count;
    }
};