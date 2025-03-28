class Solution {
public:
    void merge(int n1, int n2,vector<int>& nums1, vector<int>& nums2, vector<int>& mergeSorted){
        int n1Left = 0;
        int n2Left = 0;

        while (n1Left < nums1.size() && n2Left < nums2.size()) {
            if (nums1[n1Left] < nums2[n2Left]) {
                mergeSorted.push_back(nums1[n1Left]);
                n1Left++;
            } else {
                mergeSorted.push_back(nums2[n2Left]);
                n2Left++;
            }
        }
        
        while (n1Left < nums1.size()) {
            mergeSorted.push_back(nums1[n1Left]);
            n1Left++;
        }

        while (n2Left < nums2.size()) {
            mergeSorted.push_back(nums2[n2Left]);
            n2Left++;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> mergeSorted;

        merge(n1, n2, nums1, nums2, mergeSorted);

        int n = mergeSorted.size();
        
        if (n % 2 == 0) {
            int mid = (n - 1) / 2;
            return (mergeSorted[mid] + mergeSorted[mid + 1]) / 2.0;
        } else {
            int mid = (n - 1) / 2;
            return mergeSorted[mid];
        }
    }
};
