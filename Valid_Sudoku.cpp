# number : 36

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9], cols[9][9], box[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                rows[i][j] = 0;
                cols[i][j] = 0;
                box[i][j] = 0;
            }
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int box_index = (i / 3) * 3 + j / 3;
                    int num = board[i][j] - '0' - 1;
                    rows[i][num] += 1;
                    cols[j][num] += 1;
                    box[box_index][num] += 1;
                    if (rows[i][num] > 1 || cols[j][num] > 1 || box[box_index][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
