# number : 79

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        _board = board;
        if (word.length() <= 0)
            return true;
        row = (int)_board.size();
        if (row <= 0)
            return false;
        col = (int)_board[0].size();
        _word = word;
        length_of_word = _word.length();
        
        use_case = new int*[row];
        for (int i = 0; i < row; i++)
        {
            use_case[i] = new int[col];
            memset(use_case[i], 0, sizeof(int) * col);
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (_board[i][j] == word[0])
                {
                    use_case[i][j] = 1;
                    if (check(i, j, 1))
                        return true;
                    else
                        use_case[i][j] = 0;
                }
            }
        }
        return false;
    }
    
    bool check(int row_index, int col_index, int index_in_string)
    {
        if (index_in_string == length_of_word)
            return true;
        for (int i = 0; i < 4; i++)
        {
            int r = row_index + direction[i][0];
            int c = col_index + direction[i][1];
            if (is_on_board(r, c))
            {
                if (_board[r][c] == _word[index_in_string] && use_case[r][c] == 0)
                {
                    use_case[r][c] = 1;
                    bool result = check(r, c, index_in_string + 1);
                    if (!result)
                    {
                        use_case[r][c] = 0;
                    }
                    else
                        return result;
                }
            }
        }
        return false;
    }
    /* 检查坐标i，j是否越界 */
    bool is_on_board(int i, int j) {
        bool result = (i >= 0 && i < row && j >= 0 && j < col);
        return result;
    }
    
private:
    vector<vector<char>> _board;
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};/* 四个相邻位置 */
    int **use_case;/* 是否使用过 */
    string _word;
    int row, col, length_of_word;
};
