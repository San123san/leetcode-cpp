In int, .size() is not work.

priority_queue<int, vector<int>, greater<int>> pq; // this always create minHeap

The expression `k % n` is used to handle cases where the number of rotations `k` is greater than the array length `n`. Rotating an array by `k` steps is equivalent to rotating it by `k % n` steps, as any full rotations (i.e., multiples of `n`) bring the array back to its original position. This helps optimize the solution by reducing unnecessary rotations and ensuring efficiency. New head=n-k and new tail=n-k-1

Choose greedy algorithms when you need a fast and efficient solution to an optimization problem, and you have reason to believe that locally optimal choices will lead to a good global solution.

In backtracking, there may be duplicate elements. Keep in mind to remove duplicate elements if needed.

unordered_map<int, vector<int>> map; , in this you can add multiple value(pairs) with keys

In divide and conquer, in calculation you cant something like this to get sum = findSum(...) + findSum(...)
return sum
but in comparision can do like this max = max(findMax(...), findMax(...) )
return max

In this code, unordered_map.find(key) != unordered_map.end() checks if a specific key exists in the map. If the key is found, it returns the corresponding value; otherwise, it means the key is not present in the map. This allows for efficient lookups and insertions, ensuring average O(1) time complexity.

Key Signs You Might Need Sliding Window:
1)You are working with contiguous subarrays.
2)You need to minimize or maximize something (difference, sum, product, etc.) over a range of elements.
3)The problem involves a range (difference, sum, or other metric) and asks for the smallest/largest possible value over that range.

Pair Sum Using Two-Pointer Approach:
The two-pointer technique can be used to find a pair of elements in a sorted array whose sum equals a given target. Start by placing one pointer at the beginning (left) and the other at the end (right) of the array. If the sum of the values at both pointers equals the target, the pair is found. If the sum is smaller, move the left pointer to the right to increase the sum, and if it's larger, move the right pointer to the left to decrease the sum. This approach works in O(n) time.


n C++, the default priority_queue is a max-heap, meaning:
When you call .pop(), it removes the largest element (i.e., the element with the highest priority).

Recursion & Backtracking Notes (C++)
1)If you pass a variable by reference (&), you must undo changes manually (e.g., pop_back(), swap back) for correct backtracking.
2)If you pass it by value (copy), no need to undo — each recursive call gets a separate copy that is destroyed after return.
3)Recursion is sequential, not parallel — it explores one path at a time like depth-first traversal of a tree; return naturally "backtracks" up the call stack.
