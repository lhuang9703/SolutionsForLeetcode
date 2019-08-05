# number : 945

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int result = 0;
        int len = A.size();
        if (len <= 1)
            return result;
        sort(A.begin(), A.end());
        for (int i = 0; i < len - 1; i++) {
            if (A[i + 1] <= A[i]) {
                result += (A[i] - A[i + 1] + 1);
                A[i + 1] = A[i] + 1;
            }
        }
        return result;
    }
};
