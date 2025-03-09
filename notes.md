In int, .size() is not work.

priority_queue<int, vector<int>, greater<int>> pq; // this always create minHeap

The expression `k % n` is used to handle cases where the number of rotations `k` is greater than the array length `n`. Rotating an array by `k` steps is equivalent to rotating it by `k % n` steps, as any full rotations (i.e., multiples of `n`) bring the array back to its original position. This helps optimize the solution by reducing unnecessary rotations and ensuring efficiency.
