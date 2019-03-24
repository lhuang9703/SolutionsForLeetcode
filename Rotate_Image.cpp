# number : 48

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = (int)matrix.size();
        if (length <= 1)
            return;
        for (int i = 0; i < length; i++)
            for (int j = 0; i + j <= length - 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[length - j - 1][length - i - 1];
                matrix[length - j - 1][length - i - 1] = temp;
            }
        reverse(matrix.begin(), matrix.end());
    }
};
