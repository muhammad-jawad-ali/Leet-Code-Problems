class Solution {
public:
    int smallestEvenMultiple(int n) {
        int i=1;
        while(1){
            if(i%2 == 0 && i%n==0){
                cout << i << endl;
                break;
            }
            i++;
        }
        return i;
    }
};