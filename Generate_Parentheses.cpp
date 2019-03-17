# number : 22

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0)
            return result;
        addParentheses(result, "", n, 0, 0);
        return result;
    }
    void addParentheses(vector<string>& result, string str, int n, int left, int right)
    {
        if (right == n)
        {
            result.push_back(str);
            return;
        }
        if (left < n)
            addParentheses(result, str + "(", n, left + 1, right);
        if (right < left)
            addParentheses(result, str + ")", n, left, right + 1);
    }
};
