class Solution {
public:
    int countSmallerEqual(vector<vector<int>>& matrix, int mid){
        int nRow = matrix.size();
        int count = 0;
        int row = 0;
        int col = nRow - 1;

        while(row < nRow && col >= 0){
            if(matrix[row][col] <= mid){
                count += (col + 1);
                row++;
            } else {
                col--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int nRow = matrix.size();
        int low = matrix[0][0];
        int high = matrix[nRow-1][nRow-1];

        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int count = countSmallerEqual(matrix, mid);

            if (count < k){
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
