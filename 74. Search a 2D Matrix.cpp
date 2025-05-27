class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLength = matrix.size();
        int colLength = matrix[0].size();
        int totalLength = rowLength * colLength;

        int left = 0;
        int right = totalLength-1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            int midElement = matrix[mid / colLength][mid % colLength];

            if(midElement == target) {
                return 1;
            } 
            else if (target < midElement) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return 0;
    }
};
