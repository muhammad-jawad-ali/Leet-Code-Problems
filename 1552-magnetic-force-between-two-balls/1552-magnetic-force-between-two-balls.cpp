class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        if(m==2){
            return *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());
        }
        else if {
            position.size()/m <= 2;
        }
    }
};