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

        // int currMin = arr[0];
        // int currMax = arr[0];
        // int maxProd = arr[0];

        // for(int i = 1 ; i< n;i++){
        //     int temp = max({arr[i],arr[i]*currMax,arr[i]*currMin});
            
        //     currMin = min({arr[i],arr[i]*currMax,arr[i]*currMin});

        //     currMax = temp;
        //     maxProd = max(maxProd,currMax);
        // }

        //third approach by traversing in both directions
        int maxProd = INT_MIN;
        int lefttoright = 1;
        int righttoleft = 1;

        for(int i = 0;i < n;i++){
            if(lefttoright == 0){
                lefttoright =1;
            }
            if(righttoleft == 0){
                righttoleft = 1;
            }

            lefttoright *= arr[i];

            righttoleft *= arr[n-i-1];

            maxProd = max({lefttoright,righttoleft,maxProd});
        }

        return maxProd;
    }
};