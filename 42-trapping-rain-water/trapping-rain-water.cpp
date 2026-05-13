class Solution {
// public:
    // int trap(vector<int>& height) {
    //     stack<int> st;
    //     int water = 0;

    //     for(int i = 0;i < height.size();i++){
    //         // current bar is taller than the stack
    //         while(!st.empty()  && height[i] > height[st.top()]){
    //             int bottom = st.top();
    //             st.pop();

    //             if(st.empty()) break;

    //             int left = st.top();
    //             int width = i-left -1;
    //             int boundedHeight  = min(height[left],height[i]) - height[bottom];
    //             water += width * boundedHeight;
    //         }
    //         st.push(i);
    //     }
    //     return water;
    // }

public: 
    vector<int> getLeftMax(vector<int> &height,int n){
        vector<int> leftMax(n);
        leftMax[0] = height[0];

        for(int i = 1;i< n;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
        }
        return leftMax;
    }

    vector<int> getRightMax(vector<int> &height,int n){
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];

        for(int i = n-2;i >= 0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }
        return rightMax;
    }


    int trap(vector<int>& height){
        int ans = 0;
        int n = height.size();
        vector<int> left_max = getLeftMax(height,n);
        vector<int> right_max = getRightMax(height,n);


        for(int i = 0;i < n;i++){
            int width = 1;
            int h = min(left_max[i],right_max[i]) - height[i];
            ans += h;
        }
        return ans;


        
    }

};