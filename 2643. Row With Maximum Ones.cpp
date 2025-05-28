class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int nRow = mat.size();
        int nCol = mat[0].size();

        int maxRow = 0;
        int maxNums = 0;
        for(int i = 0; i < nRow; i++){
            int maxNum = 0;
            for(int j = 0; j < nCol; j++){
                if(mat[i][j] == 1){
                    maxNum += 1;
                }
            }
            if(maxNum > maxNums){
                maxRow = i;
                maxNums = maxNum;
            }
        }
        return {maxRow, maxNums};
    }
};
