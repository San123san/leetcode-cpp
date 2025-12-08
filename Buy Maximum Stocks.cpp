class Solution {
  public:
    int buyMaximumProducts(int n, int k, int price[]) {
        // Write your code here
        int c = 0;
        vector<pair<int, int>> pair;
        
        for(int i = 0; i < n; i++){
            pair.push_back({price[i], i + 1});
        }
        
        sort(pair.begin(), pair.end());
        
        for(int i = 0; i < n; i++){
            int ip = pair[i].first;
            int id = pair[i].second;
            
            if(k >= (ip * id)){
                k -= (ip * id);
                c += id;
            } else {
                c += (k/ip);
                break;
            }
        }
        return c;
    }
};
