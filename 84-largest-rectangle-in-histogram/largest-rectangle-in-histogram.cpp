class Solution {
public:
    vector<int> getNSR(vector<int> &heights){
        int n = heights.size();
        vector<int> NSR(n);
        stack<int> st;

        for(int i = n-1;i >= 0;--i){
            if(st.empty()){
                NSR[i] = n;
            }else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }

                if(st.empty()){
                    NSR[i] = n;
                }else{
                    NSR[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    vector<int> getNSL(vector<int> &heights){
        int n = heights.size();
        vector<int> NSL(n);
        stack<int> st;

        for(int i = 0;i < n;++i){
            if(st.empty()){
                NSL[i] = -1;
            }else{
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }

                if(st.empty()){
                    NSL[i] = -1;
                }else{
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        vector<int> NSR = getNSR(heights);
        vector<int> NSL = getNSL(heights);


        for(int i = 0;i< n;i++){
            int width = NSR[i]-NSL[i]-1;
            int area = width*heights[i];
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};