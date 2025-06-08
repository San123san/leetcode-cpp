class Solution {
public:
    bool isSafe(const string& store) {
        int count = 0;
        for (int i = 0; i < store.length(); i++) {
            if (store[i] == '(') {
                count++;
            } else if (store[i] == ')') {
                count--;
                if (count < 0) return false;  
            }
        }
        return count == 0;
    }

    void solve(int idx, int total_length, int n, int count, string& store, const string& s, unordered_set<string>& result) {
        if (store.length() == total_length) {
            if (isSafe(store)) {
                result.insert(store);
            }
            return;
        }

        if (idx >= n) return;

        // Option 1: Skip current character (if it's a parenthesis and we still have some to remove)
        if ((s[idx] == '(' || s[idx] == ')') && count > 0) {
            solve(idx + 1, total_length, n, count - 1, store, s, result);
        }

        // Option 2: Include current character
        store.push_back(s[idx]);
        solve(idx + 1, total_length, n, count, store, s, result);
        store.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int removeLeft = 0, removeRight = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                removeLeft++;
            } else if (s[i] == ')') {
                if (removeLeft > 0) {
                    removeLeft--;
                } else {
                    removeRight++;
                }
            }
        }

        int total_remove = removeLeft + removeRight;
        int total_length = n - total_remove;

        unordered_set<string> result_set;
        string store = "";
        solve(0, total_length, n, total_remove, store, s, result_set);

        return vector<string>(result_set.begin(), result_set.end());
    }
};
