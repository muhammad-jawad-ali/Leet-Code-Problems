class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int N = roads.size();
        int *arr = new int[n];
        long long res=0;
        for(int i=0;i<n;i++){
            arr[i] = 0; 
        }
        for(int i=0;i<N;i++){
            arr[roads[i][0]]++;
            arr[roads[i][1]]++;  
        }
        vector<pair<long long, long long>> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back({arr[i], i});
        }
        cout << endl;

        sort(nums.begin(), nums.end());
        
        for (long long i = n-1; i >=0; --i) {
            cout << nums[i].first << ": " << nums[i].second << endl;
            res += (i+1) * nums[i].first;
        }



        return res;
    }
};