# number : 221

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int length = 0;
        int rows = (int)matrix.size();
        if (rows <= 0)
            return 0;
        int cols = (int)matrix[0].size();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = matrix[i][j] - '0';
            }
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    matrix[i][j] = 1 + Min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
                }
            }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] > length)
                    length = matrix[i][j];
            }
        return length * length;
    }
    int Min(int a, int b, int c)
    {
        if (a < b)
            return a < c ? a : c;
        else
            return b < c ? b : c;
    }
};
