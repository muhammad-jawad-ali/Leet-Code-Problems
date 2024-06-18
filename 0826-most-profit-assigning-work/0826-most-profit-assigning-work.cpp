class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector< pair<int, int> > list1;
        int prof = 0;
        
        for (int i = 0; i < profit.size(); i++) {
            list1.push_back(make_pair(profit[i], difficulty[i]));
        }

        sort(list1.begin(), list1.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // Sort by profit if difficulties are the same
            }
            return a.first < b.first; // Sort primarily by difficulty
        });

        // Debug statement, can be removed
        for(int i = profit.size()-1; i >=0 ; i--) {
            cout << list1[i].first << ", " << list1[i].second << endl;
        }

        for(int i=0;i<worker.size();i++){
            for(int j=difficulty.size()-1;j>=0;j--){
                if(worker[i] >= list1[j].second){
                    prof += list1[j].first;
                    break;
                }
            }
        }
        return prof;
    }
};











/*
int prof=0;
        int temp=0;
        int index=0;
        for(int i=0;i<worker.size();i++){
            temp=0;
            index=0;
            for(int j=0;j<difficulty.size();j++){
                if(worker[i] == difficulty[j]){
                    prof+=profit[j];
                    cout << profit[j]  << "-"<< endl;
                    temp = 0;
                    break;
                }
                else if(worker[i] > difficulty[j] && profit[j] > temp ){
                    cout << worker[i] << ", " << difficulty[j]  << ",t= " << temp << endl;
                    temp = profit[j];
                    index = j;
                }
            }
            if(temp!=0){
            prof += profit[index];
            cout << profit[index] << endl;}
        }
        return prof;



*/