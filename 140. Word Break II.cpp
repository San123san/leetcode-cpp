class Solution {
public:
    void solve(int idx, int size, int n, string& s, vector<string>& wordDict, string& path, vector<string>& ans){
        if(idx == n){
            ans.push_back(path);
            return;
        }

        for(int i = idx; i < n; i++){
            string word = s.substr(idx, size + 1);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                string temp = path;
                if(!temp.empty()) temp += " ";
                temp += word;
                solve(i + 1, 0, n, s, wordDict, temp, ans);
            }
            size++;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        int n = s.length();
        string path = "";

        solve(0, 0, n, s, wordDict, path, ans);

        return ans;
    }
};
