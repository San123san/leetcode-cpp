class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mp;
        unordered_map<char, char> reverse_mp;

        for(int i = 0; i < s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if(mp.find(c1) != mp.end()){
                if(mp[c1] != c2) return false;
            } else {
                if(reverse_mp.find(c2) != reverse_mp.end()) return false;
                mp[c1] = c2;
                reverse_mp[c2] = c1;
            }
        }
        return true;
    }
};
