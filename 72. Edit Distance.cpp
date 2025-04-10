class Solution {
public:
    int dp(int i, int j, string& word1, string& word2, vector<vector<int>>& memo){
        if(i == word1.length()) return word2.length() - j;
        if(j == word2.length()) return word1.length() - i;

        if(memo[i][j] != -1) return memo[i][j];

        if(word1[i] == word2[j]){
            memo[i][j] = dp(i + 1, j + 1, word1, word2, memo);
        }else{
            int insertWord = dp(i, j + 1, word1, word2, memo);
            int deleteWord = dp(i + 1, j, word1, word2, memo);
            int removeWord = dp(i + 1, j + 1, word1, word2, memo);

            memo[i][j] = 1 + min({insertWord, deleteWord, removeWord});
        }
        return memo[i][j];
    }
    int minDistance(string word1, string word2) {
        int w1 = word1.length();
        int w2 = word2.length();
        vector<vector<int>> memo(w1 + 1, vector<int>(w2 + 1, -1));
        int res = dp(0, 0, word1, word2, memo);
        return res;
    }
};
