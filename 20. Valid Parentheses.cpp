class Solution {
public:
    bool isValid(string s) {
        stack<string> find;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
              find.push(string(1, s[i]));  
            } else {
                if(find.empty()) return false;

                string top = find.top();
                find.pop();

                if((s[i] == ')' && top != "(") ||
                (s[i] == ']' && top != "[") ||
                (s[i] == '}' && top != "{")) return false;
            }
        }
        return find.empty();
    }
};
