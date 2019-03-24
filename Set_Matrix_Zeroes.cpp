# number : 73

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLength = (int)matrix.size();
        int colLength = (int)matrix[0].size();
        int i, j;
        int *rowFlag = new int[rowLength];
        int *colFlag = new int[colLength];
        memset(rowFlag, 0, sizeof(int) * rowLength);
        memset(colFlag, 0, sizeof(int) * colLength);
        /* 找出哪些行和哪些列有0 */
        for (i = 0; i < rowLength; i++)
            for (j = 0; j < colLength; j++)
                if (matrix[i][j] == 0)
                {
                    rowFlag[i] = 1;
                    colFlag[j] = 1;
                }
        /* 有0的行清0 */
        for (i = 0; i < rowLength; i++)
            if (rowFlag[i] == 1)
                for (j = 0; j < colLength; j++)
                    matrix[i][j] = 0;
        /* 有0的列清0 */
        for (j = 0; j < colLength; j++)
            if (colFlag[j] == 1)
                for (i = 0; i < rowLength; i++)
                    matrix[i][j] = 0;
    }
};
