class Solution {
public:
    vector<string> ans;
    void solve(string& num,int target,int index,long curr,long prev,string path){
        if(index == num.size()){
            if(curr == target){
                ans.push_back(path);
            }
            return;
        }

        for(int i = index;i < num.size();i++){
            // avoid leading zero
            if(i > index && num[index] == '0') break;

            string part = num.substr(index,i-index+1);
            long val = stol(part);

            if(index == 0){
                // first number (no operator)
                solve(num,target,i+1,val,val,part);
            }else{
                // +
                solve(num,target,i+1,curr+val,val,path+"+"+part);
                // -
                solve(num,target,i+1,curr-val,-val,path+"-"+part);
                // *
                solve(num,target,i+1,curr-prev+(prev*val),prev*val,path+"*"+part);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,0,0,"");
        return ans;
    }
};