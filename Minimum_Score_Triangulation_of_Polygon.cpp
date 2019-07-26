# number : 1039

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int len = A.size();
        int **matrix = new int*[len];
        for (int i = 0; i < len; i++) {
            matrix[i] = new int[len];
            memset(matrix[i], 0, sizeof(matrix[i]));
        }
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (j - i == 1) {
                    matrix[i][j] = 0;
                }
                else if (j - i == 2) {
                    matrix[i][j] = A[i] * A[i + 1] * A[j];
                }
                else {
                    int tmp = INT_MAX;
                    for (int k = i + 1; k < j; k++) {
                        if ((matrix[i][k] + matrix[k][j] + A[i] * A[j] * A[k]) < tmp)
                            tmp = matrix[i][k] + matrix[k][j] + A[i] * A[j] * A[k];
                    }
                    matrix[i][j] = tmp;
                }
            }
        }
        return matrix[0][len - 1];
    }
};
