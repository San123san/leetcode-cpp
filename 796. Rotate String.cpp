class Solution {
public:
    bool rotateString(string s, string goal) {
          int sLength = s.length();
        if (sLength != goal.length()) {
            return false;
        }

        for (int k = 0; k < sLength; k++) {
            int j = 0;
            bool isMatch = true;

            for (int i = k; i < sLength; i++) {
                if (s[i] != goal[j]) {
                    isMatch = false;
                    break;
                }
                j++;
            }
            for (int i = 0; i < k; i++) {
                if (s[i] != goal[j]) {
                    isMatch = false;
                    break;
                }
                j++;
            }

            if (isMatch && j == sLength) {
                return true;
            }
        }

        return false;
    }
};
