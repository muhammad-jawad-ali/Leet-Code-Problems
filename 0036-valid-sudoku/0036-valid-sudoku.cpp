class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int box[9][9] = {0};
        vector<vector<int>> boardINT(9,vector<int>(9, 0));

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    boardINT[i][j] = board[i][j] - '0';
                    //row
                    if(row[i][boardINT[i][j]-1] == 1){
                        return false;
                    }
                    row[i][boardINT[i][j]-1] = 1;

                    //col
                    if(col[boardINT[i][j]-1][j] == 1){
                        return false;
                    }
                    col[boardINT[i][j]-1][j] = 1;

                    //box
                    if(box[ (i/3)*3 +j/3 ][ boardINT[i][j]-1 ] == 1){
                        return false;
                    }
                    box[ (i/3)*3 +j/3 ][ boardINT[i][j]-1 ] = 1;
                } 
            }
        }
        return true;
    }
};