class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        // first lets flatten the array;
        vector<int> a;

        for(auto arr: grid){
            for(auto num: arr){
                a.push_back(num);
            }
        }

        long long n = a.size();
        long long s2n = (n*(n+1)*(2*n +1))/6;
        long long sn = (n*(n+1))/2;

        long long sum = 0;
        long long squareSum = 0;

        for(auto num: a ){
            sum += num;
            squareSum = squareSum +((long long)num*(long long)num);
        }


        long long val1 = sum - sn;
        long long val2 = squareSum - s2n;

        val2 = val2/val1;

        long long x = (val1+val2)/2;
        long long y = x - val1;

        return {(int)x,(int)y};


    }
};