class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1; // The smallest number that we cannot currently form
        int patches = 0; // Number of patches added
        int i = 0; // Index to traverse through nums

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // If the current number in nums can be used to extend the range
                miss += nums[i];
                i++;
            } else {
                // Otherwise, we need to patch the array by adding miss itself
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
};




























/*
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int sum=0;
        int len = nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            sum=0;
            int j=0;
            while(sum!=i && j<len){
                sum += nums[j];
                if(sum>i){
                    sum -= nums[j];
                    break; 
                }
                j++;
            }
            if(sum != i || j==len){
                nums.insert(nums.begin() + j, i); 
                count++;
                cout << i << endl;
                for (int c: nums)
                    std::cout << c << ' ';
                cout << endl;
            }
        }
        return count;
    }
};


*/










/*
int size = nums.size();
        for(int i=size-1;i>0;i--){
            if(n/2 == nums[i]){
                n /= 2;
            }
        }
        int count=0;
        int len = log2 (n);
        int *arr = new int [len+1];
        for(int i=0;i<len+1;i++){
            arr[i] = pow(2,i); 
        }
        for(int i=0;i<=len;i++){
            cout << arr[i] << " ";
        }
        return count;

*/