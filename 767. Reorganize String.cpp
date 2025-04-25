class Solution {
public:
    typedef pair<int, char> p;
    string reorganizeString(string s) {
        int n = s.length();

        vector <int> count(26, 0);

        for(char& ch: s){
            count[ch - 'a']++;
            if(count[ch - 'a'] > (n+1)/2){
                return "";
            }
        }

        priority_queue<p, vector<p>> pq;

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch - 'a'] > 0){
                pq.push({count[ch - 'a'], ch});
            }
        }

        string res = "";
        while(pq.size() >= 2){
            auto P1 = pq.top();
            pq.pop();

            auto P2 = pq.top();
            pq.pop();

            res.push_back(P1.second);
            P1.first--;

            res.push_back(P2.second);
            P2.first--;

            if(P1.first > 0){
                pq.push(P1);
            }

            if(P2.first > 0){
                pq.push(P2);
            }
        }
        if(!pq.empty()){
                res.push_back(pq.top().second);
            }
        return res;
    }
};
