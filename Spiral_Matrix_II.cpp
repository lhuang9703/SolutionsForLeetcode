# number : 59

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int count = n * n;
        int i = 0, j = 0;
        int value = 1;
        int d = 0;
        while (count)
        {
            v[i][j] = value++;
            if (!judge(n, i + D[d][0], j + D[d][1], v))
            {
                d += 1;
                d %= 4;
            }
            i += D[d][0];
            j += D[d][1];
            count--;
        }
        return v;
    }
    bool judge(int n, int i, int j, vector<vector<int>>& v) {
        bool condition = (0 <= i && i < n && 
                          0 <= j && j < n && 
                          v[i][j] == 0);
        return condition;
    }
    int D[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
};
