// Source : https://leetcode-cn.com/problems/n-queens/description/
// Number : 51
// Author : HL
// Date   : 2018-09-16
// Kill   : 99.62%

/********************************************************************************** 
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
**********************************************************************************/

class Solution {
public:
    bool isOK(int row) {
        for (int i = 0; i < row; i++) {
            if (arr[row] == arr[i] || abs(arr[row] - arr[i]) == (row - i))
                return false;
        }
        return true;
    }
    
    void addSolution(int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                if (j == arr[i])
                    s += 'Q';
                else
                    s += '.';
            }
            temp.push_back(s);
        }
        result.push_back(temp);
    }
    
    void putQueen(int row, int n) {
        if (row == n)
            addSolution(n);
        else {
            for (int i = 0; i < n; i++) {
                arr[row] = i;
                if (isOK(row)) {
                    putQueen(row + 1, n);
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        arr = new int[n];
        putQueen(0, n);
        return result;
    }
private:
    int *arr;
    vector<vector<string>> result;
};
