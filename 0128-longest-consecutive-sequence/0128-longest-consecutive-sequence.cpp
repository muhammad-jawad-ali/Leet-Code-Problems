class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> arr;
        for(int x: nums) arr.insert(x);

        int count = 1;
        int max = 0;
        for(int x: arr){
            if(!arr.contains(x-1)) {
                count = 1;
                while(arr.contains(x+1)){
                    x++;
                    count++;
                }
                if(max<count){
                    max = count;
                }
            }
        }

        return max;
    }
};