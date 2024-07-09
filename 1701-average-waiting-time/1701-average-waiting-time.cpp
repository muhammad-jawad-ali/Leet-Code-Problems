class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int N = customers.size();
        cout << N << endl;
        double sum=0;
        double crrT = customers[0][0] ;
        for(int i=0;i<N;i++){
            if(i>0){
                if(crrT > customers[i][0] ){
                    sum += (crrT - customers[i][0]);
                }
                else{
                    crrT = customers[i][0];
                }
            }
            sum += customers[i][1];
            crrT += customers[i][1];
            cout << sum << ", " << crrT << endl;
        }
        return sum/N;
    }
};