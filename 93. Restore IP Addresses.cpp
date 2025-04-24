class Solution {
public:
    void backtrack(string s, int idx, string curIP, int segment, vector<string>& res){
        if (segment == 4) {
            if (idx == s.length()) {
                res.push_back(curIP);
            }
            return;
        }
        if (idx == s.length()) {
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (idx + len > s.length()) {
                break;
            }
            string part = s.substr(idx, len);

            if ((part.length() > 1 && part[0] == '0') || stoi(part) > 255) {
                continue;
            }

            backtrack(s, idx + len, curIP + (segment > 0 ? "." : "") + part, segment + 1, res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;

        backtrack(s, 0, "", 0, res);
        return res;
    }
};
