#include <vector>
#include <iostream>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> arr;
        for(int i = 0; i < n; i++){
            arr.push_back(i + 1);
        }
        
        int index = 0;
        for(int j = 1; j < n; j++){
            int count = 0;
            while(count < k){
                if(arr[index] != -1){
                    count++;
                }
                if(count == k) break;  
                index++;
                if(index == n){
                    index = 0;
                }
            }
            arr[index] = -1;

            while(arr[index] == -1){  
                index++;
                if(index == n){
                    index = 0;
                }
            }

            for(int k = 0; k < n; k++){
                cout << arr[k] << " ";
            }
            cout << "---" << j << endl;
        }

        for(int k = 0; k < n; k++){
            if(arr[k] != -1){
                return arr[k];
            }
        }

        return 0;
    }
};
