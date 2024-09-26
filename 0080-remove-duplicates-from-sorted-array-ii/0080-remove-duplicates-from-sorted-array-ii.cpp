class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int freq = 1;
        int k = 0;
        nums[k++] = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]){
                freq++;
            }
            if(nums[i-1] != nums[i]){
                freq = 1;
            }
            if(freq <= 2){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};