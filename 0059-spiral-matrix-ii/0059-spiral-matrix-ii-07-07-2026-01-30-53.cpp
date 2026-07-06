class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));

        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int count = 1;

        while(left <= right && top <= bottom){
            for(int j = left ; j <= right;j++){
                res[top][j] = count++;
            }
            top++;

            for(int i = top;i <= bottom;i++){
                res[i][right] = count++;
            }
            right--;

            if(top<= bottom){
                for(int j = right;j >= left;j--){
                    res[bottom][j] = count++;
                }
                bottom--;
            }

            if(left <= right){
                for(int i = bottom;i >= top;i--){
                    res[i][left] = count++;
                }
                left++;
            }
        }
        return res;
    }
};