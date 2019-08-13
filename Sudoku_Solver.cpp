# number : 37

class Solution {
public:
    int rows[9][10], cols[9][10], box[9][10];
    bool solved = false;
    
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int box_index = i / 3 * 3 + j / 3;
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    box[box_index][num] = 1;
                }
            }
        }
        dfs(0, 0, board);
    }
    
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row >= 9) {
            solved = true;
            return;
        }
        if (board[row][col] == '.') {
            int box_index = row / 3 * 3 + col / 3;
            for (int num = 1; num <= 9; num++) {
                if (rows[row][num] != 1 &&
                    cols[col][num] != 1 && 
                    box[box_index][num] != 1) {
                    board[row][col] = '0' + num;
                    rows[row][num] = cols[col][num] = box[box_index][num] = 1;
                    if (col < 8)
                        dfs(row, col + 1, board);
                    else
                        dfs(row + 1, 0, board);
                    
                    if (!solved) {
                        board[row][col] = '.';
                        rows[row][num] = cols[col][num] = box[box_index][num] = 0;    
                    }
                }
            }
        }
        else {
            if (col < 8)
                dfs(row, col + 1, board);
            else
                dfs(row + 1, 0, board);
        }
    }
};
