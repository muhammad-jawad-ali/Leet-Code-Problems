class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        if(r == 0 || c == 0){
            return {};
        }
        
        vector <int> res;

        for(int i=0;i<r;i++){
            int minE = *min_element(matrix[i].begin(), matrix[i].end());
            int minI = distance(matrix[i].begin(), min_element(matrix[i].begin(), matrix[i].end()));
            
            cout << minE << "    " << minI << endl;
            bool flag = true;

            for(int j=0;j<r;j++){
                if(matrix[j][minI] > minE){
                    flag = false;
                    break;
                }
            }

            if(flag == true){
                res.push_back(minE);
            }
        }
        return res;
    }
};