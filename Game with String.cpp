class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        int n = s.length();
        
        if (k >= n) return 0;
        
        const int ALPHABET_SIZE = 26;
        vector<int> freq(ALPHABET_SIZE, 0);
        for (char ch : s) {
            freq[ch -'a']++;
        }
        
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0)
                pq.push(f);
        }
        
        while (k-- && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            if (top > 1)
                pq.push(top - 1);
        }
        
        int res = 0; 
        while (!pq.empty()) {
            int f = pq.top();
            pq.pop();
            res += f * f;
        }
        
        return res;
    }
};
