class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int count=0,dif=0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<students.size();i++){
            dif = students[i]-seats[i];
            if(dif<0){
                dif *= -1;
            }
            count += dif; 
        }
        return count;
    }
};