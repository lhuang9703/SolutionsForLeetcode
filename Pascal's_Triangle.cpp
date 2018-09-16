// Source : https://leetcode-cn.com/problems/pascals-triangle/description/
// Number : 118
// Author : HL
// Date   : 2018-09-16
// Kill   : 100.00%

/********************************************************************************** 
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> v;
        if (numRows == 0)
            return result;
        v.push_back(1);
        result.push_back(v);
        if (numRows == 1)
            return result;
        v.push_back(1);
        result.push_back(v);
        
        queue<int> q;
        q.push(1);
        q.push(1);
        int a, b;
        
        for (int i = 2; i < numRows; i++) {
            v.clear();
            v.push_back(1);
            for (int j = 0; j <= i - 2; j++){
                a = q.front();
                q.pop();
                b = q.front();
                v.push_back(a + b);
                q.push(a + b);
            }
            v.push_back(1);
            q.push(1);
            result.push_back(v);
        }
        
        return result;
    }
};
