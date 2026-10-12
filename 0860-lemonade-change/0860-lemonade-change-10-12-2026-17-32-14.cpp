class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int tens = 0;
        int twentys = 0;

        for(auto bill: bills){
            if(bill == 5){
                five++;
                continue;
            }else if(bill == 10){
                five--;
                tens++;
                if(five < 0) return false;
            }else{
                twentys++;
                if(tens > 0 && five > 0){
                    tens--;
                    five--;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }

        if(five < 0 || tens < 0) return false;
        return true;
    }
};