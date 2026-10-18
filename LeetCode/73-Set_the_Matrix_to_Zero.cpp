class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //用第一行和第一列标记是否有0（没有0的位置不会被修改 改成0的本来就要变成0）
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_row0 = false, flag_col0 = false;

        //判断第一行第一列有没有0
        for (int i=0; i<m; i++){
            if (!matrix[i][0]) flag_col0 = true;
        }

        for (int j=0; j<n; j++){
            if (!matrix[0][j]) flag_row0 =true;
        }
    
        //用第一行第一列标记
        for (int i=1; i<m;i++){
            for (int j=1; j<n; j++){
                if (!matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
            }
        }

        //修改矩阵
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }

        //修改第一行第一列
        if (flag_col0) {
            for (int i = 0; i<m; i++) matrix[i][0] = 0;
        }

        if (flag_row0){
            for (int j=0; j<n; j++) matrix[0][j] = 0;
        }

    }
};