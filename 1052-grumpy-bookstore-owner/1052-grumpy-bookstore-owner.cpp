class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,max = 0;
        int sum1 = 0;
        int len = customers.size();
        for(int i=0;i<len;i++){
            if(grumpy[i] == 0){
                sum += customers[i]; 
            }
            if(i<=(len-minutes)){
                sum1=0;
                for(int j=0;j<minutes;j++){
                    if(grumpy[i+j] == 1){
                        sum1 += customers[i+j]; 
                    }                
                }
                if(sum1 > max){
                    max = sum1;
                }
            }
            
        }
        sum += max;
        return  sum;
    }
};