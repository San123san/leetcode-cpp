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
