class kQueues {
    int n, k;
    int *arr;        // Array to store elements
    int *front;      // Front of each queue
    int *rear;       // Rear of each queue
    int *next;       // Next free slot or next element in queue
    int free;     
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // Initialize all queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        // Initialize all slots as free
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        free = 0;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if (isFull()) {
            // Handle overflow
            return;
        }

        int idx = free;
        free = next[idx];
        arr[idx] = x;

        if (front[i] == -1) {
            front[i] = idx;
        } else {
            next[rear[i]] = idx;
        }
        rear[i] = idx;
        next[idx] = -1;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if (isEmpty(i)) {
            // Handle underflow
            return -1;
        }

        int idx = front[i];
        int res = arr[idx];
        front[i] = next[idx];

        next[idx] = free;
        free = idx;

        if (front[i] == -1) {
            rear[i] = -1;
        }
        return res;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return front[i] == -1;
    }

    bool isFull() {
        // check if array is full
        return free == -1;
    }
};
