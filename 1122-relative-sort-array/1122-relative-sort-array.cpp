class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr3(arr1.size());
        int c = 0;

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    arr3[c] = arr1[j];
                    c++;
                }
            }
        }
        sort(arr1.begin(), arr1.end());

        for (int j = 0; j < arr1.size(); j++) {
            if (find(arr2.begin(), arr2.end(), arr1[j]) == arr2.end()) {
                arr3[c] = arr1[j];
                c++;
            }
        }

        return arr3;
    }
};