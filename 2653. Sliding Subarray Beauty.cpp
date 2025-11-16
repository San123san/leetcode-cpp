class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> result;
        vector<int> freq(50, 0);  // for -50 to -1

        // -------- Build first window --------
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                freq[nums[i] + 50]++;
            }
        }

        // -------- Helper: find x-th negative --------
        auto getBeauty = [&](void) {
            int count = 0;
            for (int i = 0; i < 50; i++) {
                count += freq[i];
                if (count >= x) {
                    return i - 50;   // convert index back to value
                }
            }
            return 0; // not enough negatives
        };

        result.push_back(getBeauty());

        // -------- Slide the window --------
        for (int i = k; i < nums.size(); i++) {

            // Add new number
            if (nums[i] < 0) {
                freq[nums[i] + 50]++;
            }

            if (nums[i - k] < 0) {
                freq[nums[i - k] + 50]--;
            }

            result.push_back(getBeauty());
        }

        return result;
    }
};
