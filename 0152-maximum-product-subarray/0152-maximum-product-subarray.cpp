class Solution {
public:
    int maxProduct(vector<int>& arr) {
    //using the first method
        int n = arr.size();
        // int maxProd = arr[0];
        // for(int i = 0 ; i < n;i++){
        //     int mult = 1;
            
        //     for(int j = i;j < n;j++){
        //         mult *= arr[j];
        //         maxProd = max(maxProd,mult);
        //     }
        // }

        int currMin = arr[0];
        int currMax = arr[0];
        int maxProd = arr[0];

        for(int i = 1 ; i< n;i++){
            int temp = max({arr[i],arr[i]*currMax,arr[i]*currMin});
            
            currMin = min({arr[i],arr[i]*currMax,arr[i]*currMin});

            currMax = temp;
            maxProd = max(maxProd,currMax);
        }

        return maxProd;
    }
};