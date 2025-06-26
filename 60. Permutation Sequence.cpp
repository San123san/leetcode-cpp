class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }

        vector<int> fact(n, 1);
        for(int i = 1; i < n; i++){
            fact[i] = fact[i - 1] * i;
        }

        k--;

        string res = "";
        for(int i = 0; i < n; i++){
            int idx = k / fact[n - 1 - i];
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);

            k %= fact[n - 1 - i];
        }

        return res;
    }
};

// tle come
// class Solution {
// public:
//     void solve(int idx, string& num, int n, int k, vector<string>& res) {
//         if (idx == n) {
//             res.push_back(num);  // Add the current permutation to the result vector
//             return;
//         }

//         // Generate all permutations by swapping numbers
//         for (int i = idx; i < n; i++) {
//             swap(num[idx], num[i]);  // Swap elements at idx and i
//             solve(idx + 1, num, n, k, res);  // Recurse for the next position
//             swap(num[idx], num[i]);  // Backtrack (restore the previous state)
//         }
//     }

//     string getPermutation(int n, int k) {
//         string num = "";
//         // Build the string of numbers "123...n"
//         for (int i = 1; i <= n; i++) {
//             num += to_string(i);
//         }
        
//         vector<string> res;
//         solve(0, num, n, k, res);  // Generate all permutations

//         sort(res.begin(), res.end());
        
//         // Return the kth permutation (k is 1-based index)
//         return res[k - 1];  // Since k is 1-based, access the k-1 index
//     }
// };
