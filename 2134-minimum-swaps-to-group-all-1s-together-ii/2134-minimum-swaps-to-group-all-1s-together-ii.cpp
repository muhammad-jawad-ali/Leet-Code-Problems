class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                ones++;
            }
            nums.push_back(nums[i]);
        }

        int count = accumulate(nums.begin(), nums.begin() + ones, 0);;
        int maax = count;

        for(int i=0;i<n;i++){
            count = count + nums[i+ones] - nums[i];
            maax = max(maax,count);
        }

        return ones-maax;

    }
};