class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0; 
        int n = s.length();
        int m = t.length();

        for (int i = 0; i < m && j < n; i++) {
            if (t[i] == s[j]) { 
                j++;
            }
        }
        return j == n;
    }
};
