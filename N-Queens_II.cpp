// Source : https://leetcode-cn.com/problems/n-queens-ii/description/
// Number : 52
// Author : HL
// Date   : 2018-09-16
// Kill   : 82.87%

/********************************************************************************** 
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:
Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
**********************************************************************************/

class Solution {
public:
    bool isOK(int row) {
        for (int i = 0; i < row; i++) {
            if (arr[i] == arr[row] || abs(arr[row] - arr[i]) == (row - i))
                return false;
        }
        return true;
    }
    
    void putQueen(int row, int n) {
        if (row == n)
            total++;
        else {
            for (int i = 0; i < n; i++) {
                arr[row] = i;
                if (isOK(row))
                    putQueen(row + 1, n);
            }
        }
    }
    
    int totalNQueens(int n) {
        arr = new int[n];
        putQueen(0, n);
        return total;
    }
private:
    int total;
    int *arr;
};
