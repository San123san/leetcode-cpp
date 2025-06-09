class Solution {
public:
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }    
        }
        return true;
    }
    void solve(int idx, int n, string& s, vector<string>& path, vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(path);
            return;
        }

        for(int i = idx; i < n; i++){
            if(isPalindrome(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, n, s, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        int n = s.length();
        solve(0, n, s, path, ans);

        return ans;
    }
};
