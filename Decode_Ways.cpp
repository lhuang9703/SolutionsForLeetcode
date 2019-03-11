# number : 91

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int length = s.size();
        int *result = new int[length+1];
        result[0] = 1;
        result[1] = 1;
        for (int i = 1; i < length; i++)
        {
            if (s[i] == '0')
            {
                if (s[i-1] == '1' || s[i-1] == '2')
                    result[i+1] = result[i-1];
                else
                    return 0;
            }
            else
            {
                result[i+1] = result[i];
                int temp = (s[i-1] - '0') * 10 + (s[i] - '0');
                if (temp >= 10 && temp <= 26)
                    result[i+1] += result[i-1];
            }
        }
        return result[length];
    }
};
