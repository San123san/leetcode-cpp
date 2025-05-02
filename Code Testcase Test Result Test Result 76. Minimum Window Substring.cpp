class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n) return "";

        unordered_map <char, int> mp;

        for(char &ch : t) mp[ch]++;

        int reqCount = t.length();
        int i = 0;
        int j = 0;

        int windowSize = INT_MAX;
        int start_i = 0;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0) reqCount--;

            mp[ch]--;

            while(reqCount == 0){
                int currWin = j - i + 1;

                if(windowSize > currWin){
                    windowSize = currWin;
                    start_i = i;
                } 
                

                mp[s[i]]++;
                if(mp[s[i]] > 0) reqCount++;

                i++;
            }
            j++;
        }
        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};
