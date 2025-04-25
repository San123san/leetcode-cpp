class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        for(auto c:s){
            freq[c - 'a']++;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(auto c:s){
            freq[c - 'a']--;

            if(!seen[c - 'a']){
                while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0){
                    seen[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(c);
                seen[c - 'a'] = true;
            }
        }

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
