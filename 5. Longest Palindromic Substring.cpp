//memory limit exceed
class Solution {
public:
    string findPalindrome(string s, int start, int end, string& longestPalindrome) {
        if (start > end) return longestPalindrome; 

        string currentSubstring = s.substr(start, end - start + 1);
        
        string reversedSubstring = currentSubstring;
        reverse(reversedSubstring.begin(), reversedSubstring.end());

        if (reversedSubstring == currentSubstring) {
            if (currentSubstring.size() > longestPalindrome.size()) {
                longestPalindrome = currentSubstring;  
            }
        }

        findPalindrome(s, start + 1, end, longestPalindrome);
        findPalindrome(s, start, end - 1, longestPalindrome);

        return longestPalindrome;
    }
    string longestPalindrome(string s) {
       int n = s.length();
        string longestPalindrome = "";  

        return findPalindrome(s, 0, n - 1, longestPalindrome);
    }
};


//
class Solution {
public:
    int t[1001][1001];

    bool solve(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = solve(s, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLen = INT_MIN;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j) == true) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};
