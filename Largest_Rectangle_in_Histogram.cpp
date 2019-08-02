# number: 84

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() <= 0)
            return 0;
        
        // return divideSolution(heights, 0, heights.size() - 1);
        
        return stackSolution(heights);
    }
    
    // 递增栈解法
    int stackSolution(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> s;
        s.push(-1);
        int max_area = heights[0];
        int tmp;
        for (int i = 0; i < heights.size(); i++) {
            if (s.top() == -1 || heights[i] >= heights[s.top()]) {
                s.push(i);
            }
            else {
                while (s.top() != -1 && heights[s.top()] > heights[i]) {
                    tmp = s.top();
                    s.pop();
                    int left_index = s.top();
                    auto area = heights[tmp] * (i - left_index - 1);
                    if (area > max_area)
                        max_area = area;
                }
                s.push(i);
            }
        }
        return max_area;
    }
    
    // 分治解法
    int divideSolution(vector<int>& heights, int left, int right) {
        if (left < 0 || right >= heights.size() || left > right)
            return 0;
        if (left == right) {
            return heights[left];
        }
        int min_height = INT_MAX, min_index = left;
        for (int i = left; i <= right; i++) {
            if (heights[i] < min_height) {
                min_height = heights[i];
                min_index = i;
            }
        }
        return maxValue(min_height * (right - left + 1), 
                        divideSolution(heights, left, min_index - 1), 
                        divideSolution(heights, min_index + 1, right));
    }
    
    int maxValue(int a, int b, int c) {
        if (a > b) { return a > c ? a : c; }
        else { return b > c ? b : c; }
    }
};
