class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        stack<int> s;
        int n = q.size();
        int half = n / 2;

        // Step 1: Push first half into stack
        for (int i = 0; i < half; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue stack elements back to queue (reverses first half)
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Dequeue first half elements and enqueue them to restore order
        for (int i = 0; i < half; i++) {
            q.push(q.front());
            q.pop();
        }

        // Step 4: Push first half into stack again
        for (int i = 0; i < half; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 5: Interleave stack and queue elements
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
            q.push(q.front());
            q.pop();
        }
    }
};
