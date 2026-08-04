class Solution {
public:
    bool grid_3x3_checker(vector<vector<char>>& board, int start_row, int start_col) {
        set<int> seen;

        for(int i = start_row; i < start_row + 3; i++){
            for(int j = start_col; j < start_col + 3; j++){
                if(board[i][j] != '.'){
                    if (seen.count(board[i][j] - '0'))
                        return false;
                    seen.insert(board[i][j] - '0');
                }
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            set<int> seen;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(seen.count(board[i][j] - '0') > 0) return false;
                    seen.insert(board[i][j] - '0');
                }
            }
        }

        for(int j = 0; j < 9; j++){
            set<int> seen;
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(seen.count(board[i][j] - '0') > 0) return false;
                    seen.insert(board[i][j] - '0');
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                if(!grid_3x3_checker(board, i, j))
                    return false;
            }
        }

        return true;
    }
};
