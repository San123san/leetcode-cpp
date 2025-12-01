class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
    vector<int> ans = {0, 0};
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    // sort the jobs based on deadline
    // in ascending order
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < jobs.size(); i++) {
        
        // if job can be scheduled within its deadline
        if (jobs[i].first > pq.size())
            pq.push(jobs[i].second);
        
        // replace the job with the lowest profit
        else if (!pq.empty() && pq.top() < jobs[i].second) {
            pq.pop();
            pq.push(jobs[i].second);
        }
    }

    while (!pq.empty()) {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }

    return ans;
    }
};
