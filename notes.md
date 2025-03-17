In int, .size() is not work.

priority_queue<int, vector<int>, greater<int>> pq; // this always create minHeap

The expression `k % n` is used to handle cases where the number of rotations `k` is greater than the array length `n`. Rotating an array by `k` steps is equivalent to rotating it by `k % n` steps, as any full rotations (i.e., multiples of `n`) bring the array back to its original position. This helps optimize the solution by reducing unnecessary rotations and ensuring efficiency.

Choose greedy algorithms when you need a fast and efficient solution to an optimization problem, and you have reason to believe that locally optimal choices will lead to a good global solution.

In backtracking, there may be duplicate elements. Keep in mind to remove duplicate elements if needed.

unordered_map<int, vector<int>> map; , in this you can add multiple value(pairs) with keys

In divide and conquer, in calculation you cant something like this to get sum = findSum(...) + findSum(...)
return sum
but in comparision can do like this max = max(findMax(...), findMax(...) )
return max

In this code, unordered_map.find(key) != unordered_map.end() checks if a specific key exists in the map. If the key is found, it returns the corresponding value; otherwise, it means the key is not present in the map. This allows for efficient lookups and insertions, ensuring average O(1) time complexity.
