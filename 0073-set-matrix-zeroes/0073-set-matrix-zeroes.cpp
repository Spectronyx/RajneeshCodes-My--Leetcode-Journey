class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //mark all the rows and colms -1

        // for(int i =0 ;i < n;i++){
        //     for(int j = 0;j < m;j++){
                
        //         if(matrix[i][j] == 0){
        //             for(int col = 0; col < m;col++){
        //                 if(matrix[i][col] != 0)
        //                     matrix[i][col] = -1;
        //             }
        //             for(int row = 0; row < n;row++){
        //                 if(matrix[row][j] != 0)
        //                     matrix[row][j] = -1;
        //             }
        //         }
        //     }
        // }

        // for(int i = 0;i < n;i++){
        //     for(int j = 0;j  <m;j++){
        //         if(matrix[i][j] == -1){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        //using row marker approach

        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        //second pass if row or col == 1
        // print the whole row 0

        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(row[i]== 1 || col[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};