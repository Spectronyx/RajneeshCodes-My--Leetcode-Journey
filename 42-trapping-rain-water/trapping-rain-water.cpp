class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;

        for(int i = 0;i < height.size();i++){
            // current bar is taller than the stack
            while(!st.empty()  && height[i] > height[st.top()]){
                int bottom = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top();
                int width = i-left -1;
                int boundedHeight  = min(height[left],height[i]) - height[bottom];
                water += width * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};