class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int endRow = matrix.size();
        int endCol = matrix[0].size();
        int firstRow = 0;
        int firstCol = 0;

        vector<int> res;

        int count = endRow * endCol;
        int idx = 0;

        while(idx < count){
            for(int i = firstCol; i < endCol && idx < count; i++){
                res.push_back(matrix[firstRow][i]);
                idx++;
            }
            firstRow++;

            for(int i = firstRow; i < endRow && idx < count; i++){
                res.push_back(matrix[i][endCol-1]);
                idx++;
            }
            endCol--;

            for(int i = endCol-1; i >= firstCol && idx < count; i--){
                res.push_back(matrix[endRow-1][i]);
                idx++;
            }
            endRow--;

            for(int i = endRow-1; i >= firstRow && idx < count; i--){
                res.push_back(matrix[i][firstCol]);
                idx++;
            }
            firstCol++;
        }
        return res;
    }
};
