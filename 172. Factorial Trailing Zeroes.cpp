// approach - divide and conquer
class Solution {
public:
    int countFactorsOf5(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            int num = i;
            while (num % 5 == 0) {
                count++;
                num /= 5;
            }
        }
        return count;
    }

    int divideAndConquer(int left, int right) {]
        if (left > right) {
            return 0; 
        }

        if (left == right) {
            return countFactorsOf5(left, right);
        }

        // Find the middle of the range
        int mid = left + (right - left) / 2;

        int leftCount = divideAndConquer(left, mid); 
        int rightCount = divideAndConquer(mid + 1, right);

        // Combine the results by adding the counts from both halves
        return leftCount + rightCount;
    }

    int trailingZeroes(int n) {
        return divideAndConquer(1, n);
    }
};

// time complexity - O(log n)
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
    
    while (n >= 5) {
        count += n / 5; 
        n /= 5;  
    }
    
    return count;
    }
};
