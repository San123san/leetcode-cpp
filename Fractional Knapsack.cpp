class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
    
    vector<pair<int, int>> vec(n);
    
    for(int i = 0; i < n; i++) {
        vec[i] = {val[i], wt[i]};
    }
    
    auto lambda = [](pair<int, int>& p1, pair<int, int>& p2){
        return (1.0 * p1.first)/p1.second > (1.0 * p2.first)/p2.second;
    };
    
    sort(begin(vec), end(vec), lambda);
    
    double res = 0.0;
    
    for(int i = 0; i < n; i++) {
        if(vec[i].second <= capacity) {
            res += vec[i].first;
            capacity -= vec[i].second;
        } else {
            res += (1.0 * vec[i].first/vec[i].second) * capacity;
            break;
        }
    }
    return res;
    }
};
