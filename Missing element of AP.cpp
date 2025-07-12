//Back-end complete function template for C++

class Solution {
  public:

    int findMissing(vector<int> &arr) {
        int n = arr.size();

        int diff;
        int diff1 = arr[1] - arr[0], diff2 = arr[n - 1] - arr[n - 2],
            diff3 = (arr[n - 1] - arr[0]) / n;
        if (diff1 == diff2)
            diff = diff1;
        else if (diff1 == diff3)
            diff = diff1;
        else
            diff = diff2;

        if (diff == 0)
            return arr[0];

        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            // if mid == (nth position of element in AP)-1
            // the missing element will exist in right half
            if ((arr[mid] - arr[0]) / diff == mid)
                lo = mid + 1;

            // the missing element will exist in left half
            else
                hi = mid - 1;
        }

        // after breaking out of binary search loop the missing element
        // will exist between high and low
        return arr[hi] + diff;
    }
};
