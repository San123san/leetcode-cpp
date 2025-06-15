class Solution {
public:
    void solve(int idx, int n, string& numStr, int& maxNum, bool swapped) {
        maxNum = max(maxNum, stoi(numStr));
        if (idx >= n) {
            return;
        }


        for (int i = idx; i < n; i++) {
            if(!swapped && i != idx && numStr[i] != numStr[idx]){
                swap(numStr[i], numStr[idx]);
                solve(idx + 1, n, numStr, maxNum, true);
                swap(numStr[i], numStr[idx]);
            } else {
                solve(idx + 1, n, numStr, maxNum, swapped);
            }
        }
    }
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int maxNum = num;
        int n = numStr.length();
        solve(0, n, numStr, maxNum, false);

        return maxNum;
    }
};
