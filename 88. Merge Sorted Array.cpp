class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        int iNums1 = m - 1;
        int iNums2 = n - 1;

        while(iNums1 >= 0 && iNums2 >= 0){
            if(nums1[iNums1] < nums2[iNums2]){
                nums1[i] = nums2[iNums2];
                iNums2--;
            } else {
                nums1[i] = nums1[iNums1];
                iNums1--;
            }
            i--;
        }
        while(iNums2 >= 0){
            nums1[i] = nums2[iNums2];
            i--;
            iNums2--;
        }
    }
};
