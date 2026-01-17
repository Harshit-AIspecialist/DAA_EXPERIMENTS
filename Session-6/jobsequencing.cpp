class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();

        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }


        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        int maxDeadline = 0;
        for (int d : deadline)
            maxDeadline = max(maxDeadline, d);

        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++)
            parent[i] = i;

        int jobCount = 0;
        int totalProfit = 0;
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int availableSlot = find(d);
            if (availableSlot > 0) {
                parent[availableSlot] = find(availableSlot - 1);
                jobCount++;
                totalProfit += p;
            }
        }

        return {jobCount, totalProfit};
    }
};
