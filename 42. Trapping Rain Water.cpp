//Time limit exceed
class Solution {
public:
    int trap(vector<int>& height) {
        int max_height = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            max_height = max(max_height, height[i]);
        }
        int n = height.size();
        int res = 0;
        while (max_height > 0) {
            int j = 0;
            while (j < n && height[j] == 0) {
                j = j + 1;
            }
            int k = n - 1;
            while (k >= 0 && height[k] == 0) {
                k--;
            }
            if (j < k) {
                for (int i = j; i <= k; i++) {
                    if (height[i] == 0) {
                        res += 1;
                    } else {
                        height[i] = height[i] - 1;
                    }
                }
            }
            max_height--;
        }
        return res;
    }
};

// time complexity - O(n) 
//space complexity - O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int left_max = 0;
        int right_max = 0;
        int sum = 0;

        while(left < right){
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if(left_max < right_max){
                sum += left_max - height[left];
                left++;
            }else{
                sum += right_max - height[right];
                right--;
            }
        }
        return sum;
    }
};
