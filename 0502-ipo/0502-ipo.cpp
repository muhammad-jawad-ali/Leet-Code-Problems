class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int len = profits.size();
        vector<pair<int, int>> projects(len);
        
        for (int i = 0; i < len; ++i) {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int idx = 0;

        for (int i = 0; i < k; ++i) {
            while (idx < len && projects[idx].first <= w) {
                maxHeap.push(projects[idx].second);
                ++idx;
            }

            if (maxHeap.empty()) break;

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};