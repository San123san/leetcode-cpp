class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                // When we find a closing parenthesis, check inside the stack
                if (st.empty()) return false; // Just a safety check
                
                char top = st.top();
                st.pop();

                bool flag = true; // Assume redundant unless operator found
                
                // Check the stack content until opening bracket is found
                while (!st.empty() && top != '(') {
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        flag = false;
                    }
                    top = st.top();
                    st.pop();
                }

                if (flag == true) return true; // Redundancy found
            } else {
                st.push(s[i]); // For characters other than ')', push them to stack
            }
        }
        return false;
    }
};
