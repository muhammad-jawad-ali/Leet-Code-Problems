class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        vector<int> res[2];
        for(int i=0;i<size-1;i++){
            for(int j=size-1;j>i;j--){
                if(numbers[i]+numbers[j] == target){
                    vector<int> res = {i+1,j+1};
                    return res;
                }
            }
        }
        vector<int> re = {0,0};
        return re;
    }
};