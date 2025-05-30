class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();

        for(int i = 0; i < nRow; i++){
            for(int j = i+1; j < nCol; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < nRow; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
