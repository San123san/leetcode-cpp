class Solution {
public:
    int minMovesToMakePalindrome(string s) {
         int n = s.size();
        int left = 0, right = n - 1, ans = 0;

        while(left < right) {
            int l = left, r = right;

            while(s[l] != s[r]) {
                r--;
            }

            if(l == r) {
                swap(s[r], s[r + 1]);
                ans++;
                continue;
            } else {
                while(r < right) {
                    swap(s[r], s[r + 1]);
                    ans++;
                    r++;
                }
            }

            left++;
            right--;
        }
        return ans;
    }
};
