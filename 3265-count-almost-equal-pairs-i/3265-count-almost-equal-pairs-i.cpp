class Solution {
public:
    bool comparenumbers(int a, int b) {
    // Convert numbers to strings to handle digits directly
    string sa = to_string(a);
    string sb = to_string(b);

    // Normalize lengths by adding leading zeros to the shorter number
    while (sa.length() < sb.length()) sa = '0' + sa;
    while (sb.length() < sa.length()) sb = '0' + sb;

    // Find positions where the digits differ
    vector<int> diff;
    for (int i = 0; i < sa.size(); ++i) {
        if (sa[i] != sb[i]) {
            diff.push_back(i);
            if (diff.size() > 2) return false; // More than 2 differences, cannot be made equal by a single swap
        }
    }

    // If there are no differences, the numbers are already equal
    if (diff.size() == 0) return true;

    // If exactly 2 differences, check if swapping makes them equal
    if (diff.size() == 2) {
        int i = diff[0], j = diff[1];
        swap(sa[i], sa[j]);
        return sa == sb;
    }

    return false;
}


    
    
    int countPairs(vector<int>& nums) {
        int n= nums.size();
        int count =0;
        for(int i=0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(comparenumbers(nums[i] ,nums[j]) == true){
                    cout << nums[i] << ", " << nums[j] << endl;
                    count++;
                }
            }
        }
        return count;
    }
};