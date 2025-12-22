// User function Template for C++

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
        if (M > N || (S >= 7 && 6 * N < 7 * M)) {
            return -1;
        }
        // Otherwise, minimum buying days needed
        double req = S * M;
        return ceil(req / N);
    }
};
