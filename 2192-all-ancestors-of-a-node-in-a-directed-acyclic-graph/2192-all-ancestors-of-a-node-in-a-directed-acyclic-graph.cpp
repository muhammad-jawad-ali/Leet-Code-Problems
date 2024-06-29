class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Build the adjacency list
        for (const auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Function to perform DFS and collect ancestors
        function<void(int, int)> dfs = [&](int node, int ancestor) {
            for (int parent : adj[node]) {
                if (!visited[ancestor][parent]) {
                    visited[ancestor][parent] = true;
                    ans[ancestor].push_back(parent);
                    dfs(parent, ancestor);
                }
            }
        };

        // Perform DFS for each node
        for (int i = 0; i < n; ++i) {
            dfs(i, i);
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
















/*
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int N = edges.size();
        vector<vector<int>> ans(n);
        for(int i=0;i<N;i++){
            ans[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector <int> temp = ans[i];
            for(int j = 0; j < ans[i].size() ; j++){
                for(int k=0; k<ans[ans[i][j]].size(); k++){
                    temp.push_back(ans[ans[i][j]][k]);
                }

            }
            sort(temp.begin(), temp.end());
            auto uniqueEnd = unique(temp.begin(), temp.end());
            temp.erase(uniqueEnd, temp.end());

            ans[i] = temp;
        }

        return ans;
    }
};
*/