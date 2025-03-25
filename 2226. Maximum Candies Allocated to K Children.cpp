// time limit exceed
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int max_ele = *max_element(candies.begin(), candies.end());
        int res = 0;

        while (max_ele > 0) {
            long long childrenServed = 0; 
            for (int i = 0; i < n; ++i) {
                childrenServed += candies[i] / max_ele;
            }

            if (childrenServed >= k) {
                return max_ele;
            }

            max_ele--;
        }
        return 0;
    }
};

//second approach
class Solution {
public:
    bool allocate(vector<int>& candies, int mid, long long k) {
        int n = candies.size();
        long long required = 0;
        for (int i = 0; i < n; i++) {
            required += candies[i] / mid;
            if (required >= k) {
                return true; 
            }
        }
        return required >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int max_ele = *max_element(candies.begin(), candies.end());

        int left = 1;
        int right = max_ele;
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (allocate(candies, mid, k)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};
