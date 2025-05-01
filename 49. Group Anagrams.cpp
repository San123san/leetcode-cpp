class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;

        for(auto& str: strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagram[sorted].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto& [key, pair]: anagram){
            ans.push_back(move(pair));
        }
        return ans;
    }
};
