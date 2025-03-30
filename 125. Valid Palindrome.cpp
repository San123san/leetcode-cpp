class Solution 
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);  
        }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int right = s.length() - 1;
        int left = 0;

        while (left < right) {
            if (s[left] != s[right]) {
                return 0;
            }
            left++;
            right--;
        }
        return 1;
    }
};
