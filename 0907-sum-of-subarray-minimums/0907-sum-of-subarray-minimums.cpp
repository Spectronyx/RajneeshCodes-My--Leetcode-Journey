class Solution {
public:
    // int sumSubarrayMins(vector<int>& arr) {
    //     n = arr.size();
    //     long long sum = 0;
    //     const int MOD = 1e9 + 7;

    //     for(int i = 0;i < n;i++){
    //         int minVal = arr[i];
    //         for(int j = i;j < n;j++){
    //             minVal = min(minVal,arr[j]);
    //             sum = (sum + minVal)%MOD;
    //         }
    //     }
    //     return sum;
    // }

    vector<int> getNSL(vector<int> &arr,int n){
        vector<int> result(n);
        stack<int> st;

        for(int i = 0; i < n;i++){
            if(st.empty()){
                result[i] = -1;
            }else{
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> getNSR(vector<int> &arr,int n){
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1; i >= 0;i--){
            if(st.empty()){
                result[i] = n;
            }else{
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr){
        long long sum = 0;
        int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);


        for(int i = 0;i < n;i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = rs*ls;

            long long totalSum = arr[i]*totalWays;

            sum = (sum + totalSum)%MOD;
        }
        return sum;
    }
};