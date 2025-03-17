class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        int n = prices.size()-1;
        if(n < 1) return 0;

        for (int i = 0; i <=n; i++){
            minPrice = min(minPrice, prices[i]);
            ans = max(ans, prices[i] - minPrice);
        }
        return ans;
    }
};
