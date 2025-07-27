class Solution {
public:
    int maxProduct(vector<int>& arr) {
    //using the first method
        int n = arr.size();
        int maxProd = arr[0];
        for(int i = 0 ; i < n;i++){
            int mult = 1;
            
            for(int j = i;j < n;j++){
                mult *= arr[j];
                maxProd = max(maxProd,mult);
            }
        }

        return maxProd;
    }
};