class Solution {
public:
    bool checkRecord(string s) {

        int absent = 0;
        int late = 0;

        for(char ch : s){

            if(ch == 'A'){
                absent++;
                late = 0;

                if(absent >= 2)
                    return false;
            }
            else if(ch == 'L'){
                late++;

                if(late >= 3)
                    return false;
            }
            else{ // 'P'
                late = 0;
            }
        }

        return true;
    }
};