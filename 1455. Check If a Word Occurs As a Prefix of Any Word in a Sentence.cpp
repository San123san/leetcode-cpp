class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();
        
        vector<int> lps(m, 0);
        int len = 0, j = 1;
        while (j < m) {
            if (searchWord[j] == searchWord[len]) {
                len++;
                lps[j] = len;
                j++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[j] = 0;
                    j++;
                }
            }
        }

        int wordIndex = 1;  
        int i = 0;         
        
        while (i < n) {
            while (i < n && sentence[i] == ' ') {
                i++;
            }

            int j = 0;  
            while (i < n && sentence[i] != ' ' && j < m) {
                if (sentence[i] == searchWord[j]) {
                    i++;
                    j++;
                } else {
                    if (j == 0) {
                        break; 
                    } else {
                        j = lps[j - 1];  
                    }
                }
            }

            if (j == m) {
                return wordIndex;
            }

            while (i < n && sentence[i] != ' ') {
                i++;
            }

            wordIndex++;
        }

        return -1; 
    }
};
