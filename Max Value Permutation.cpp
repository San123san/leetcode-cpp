class Solution {
  public:
    int maxValue(vector<int> &arr) {
        // Complete the function
        int mod = 1000000007;
        
        sort(arr.begin(), arr.end());
        
        long sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum = sum + (long long)arr[i]*i;
        }
        
        sum = sum % mod;
        return sum;
    }
};
