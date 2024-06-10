class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        int *temp = new int [heights.size()];
        for(int i=0;i<heights.size();i++){
            temp[i] = heights[i];
        }

        sort(heights.begin(),heights.end());
        
        for(int i=0;i<heights.size();i++){
            if(heights[i] != temp[i]){
                ans++;
            }
        }


        return ans;
    }
};