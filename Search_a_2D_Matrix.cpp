# number : 74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = (int)matrix.size();
        if (rows <= 0)
            return false;
        int cols = (int)matrix[0].size();
        if (cols <= 0)
            return false;
        int rowIndex = 0, colIndex = cols - 1;
        while (rowIndex < rows && colIndex >= 0)
        {
            if (matrix[rowIndex][colIndex] == target)
                return true;
            else if (matrix[rowIndex][colIndex] < target)
                rowIndex++;
            else
                colIndex--;
        }
        return false;
    }
};
