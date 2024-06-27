class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ans = edges[0][0];
        int ans1 = edges[0][1];
        if(ans == edges[1][0] || ans==edges[1][1])
           return ans;
        return ans1;
    }
};