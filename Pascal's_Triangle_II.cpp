// Source : https://leetcode-cn.com/problems/pascals-triangle-ii/description/
// Number : 67
// Author : HL
// Date   : 2018-09-16
// Kill   : 100.00%

/********************************************************************************** 
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
**********************************************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if (rowIndex < 0 || rowIndex > 33)
            return v;
        v.push_back(1);
        if (rowIndex == 0)
            return v;
        v.push_back(1);
        if (rowIndex == 1)
            return v;
        
        queue<int> q;
        q.push(1);
        q.push(1);
        int a, b;
        
        for (int i = 1; i < rowIndex; i++) {
            v.clear();
            v.push_back(1);
            for (int j = 0; j <= i - 1; j++){
                a = q.front();
                q.pop();
                b = q.front();
                v.push_back(a + b);
                q.push(a + b);
            }
            v.push_back(1);
            q.push(1);
        }
        
        return v;
    }
};
