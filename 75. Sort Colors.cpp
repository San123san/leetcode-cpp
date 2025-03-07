//First approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                c0 += 1; 
            }
            else if (nums[i] == 1){
                c1 += 1; 
            }
            else if (nums[i] == 2){
                c2 += 1; 
            }
        }

        for (int i = 0; i < nums.size(); ){
            while(c0 != 0){
                nums[i] = 0;
                i++;
                c0--;
            }
            while(c1 != 1){
                nums[i] = 1;
                i++;
                c1--;
            }
            while(c2 != 2){
                nums[i] = 2;
                i++;
                c2--;
            }
        }
    }
};



// Second approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = 0;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid], nums[high--]);
            }
        }
    }
};
