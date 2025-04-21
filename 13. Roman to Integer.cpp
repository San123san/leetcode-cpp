class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> roman;

        roman.insert({'I', 1});
        roman.insert({'V', 5});
        roman.insert({'X', 10});
        roman.insert({'L', 50});
        roman.insert({'C', 100});
        roman.insert({'D', 500});
        roman.insert({'M', 1000});

        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length()) {
                if (s[i] == 'I' && s[i + 1] == 'V') {
                    result += 4;
                    i++;
                    continue;
                } else if (s[i] == 'I' && s[i + 1] == 'X') {
                    result += 9;
                    i++;
                    continue;
                } else if (s[i] == 'X' && s[i + 1] == 'L') {
                    result += 40;
                    i++;
                    continue;
                } else if (s[i] == 'X' && s[i + 1] == 'C') {
                    result += 90;
                    i++;
                    continue;
                } else if (s[i] == 'C' && s[i + 1] == 'D') {
                    result += 400;
                    i++;
                    continue;
                } else if (s[i] == 'C' && s[i + 1] == 'M') {
                    result += 900;
                    i++;
                    continue;
                }
            }
            result += roman[s[i]];
        }
        return result;
    }
};
