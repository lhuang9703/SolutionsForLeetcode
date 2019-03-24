# number : 54

class Solution {
public:
    bool judge(int n, int m, int row, int col)
    {
        bool condition = (0 <= row && 
                          row < n && 
                          0 <= col && 
                          col < m && 
                          visit[row][col] != true);
        return condition;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if (row <= 0)
            return result;
        int col = matrix[0].size();
        int count = row * col;
        int i = 0, j = 0, d = 0;
        visit = vector<vector<bool> >(row, vector<bool>(col, false));
        while (count > 0) 
        {
            result.push_back(matrix[i][j]);
            visit[i][j] = true;
            if (!judge(row, col, i+D[d][0], j+D[d][1]))
            {
                d += 1;
                d = d % 4;
            }
            i += D[d][0];
            j += D[d][1];
            count--;
        }
        
        return result;
    }
    int D[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool> > visit;
};
