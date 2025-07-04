class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long square = (long long)mid * mid;
            if (num == square) {
                return true;
            }
            else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
