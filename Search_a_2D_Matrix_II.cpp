# number : 240

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int row = 0, col = n - 1;
        while (row != m && col != -1) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else    col--;
        }
        return false;
    }
};
