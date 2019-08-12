# number : 166

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if (denominator == 0)
            return "NaN";
        if ((numerator > 0 && denominator < 0) || 
            (numerator < 0 && denominator > 0))
            result += "-";
        long n = abs(static_cast<long>(numerator));
        long d = abs(static_cast<long>(denominator));
        long v = n / d;
        long m = n % d;
        result += to_string(v);
        if (m == 0)
            return result;
        result += ".";
        unordered_map<long, int> mp;
        int index = 0;
        while (m != 0) {
            if (mp.find(m) != mp.end()) {
                result += "()";
                break;
            }
            mp[m] = index++;
            n = m * 10;
            v = n / d;
            result += to_string(v);
            m = n % d;
        }
        if (mp.find(m) != mp.end()) {
            int cur = result.size() - 2;
            int t = index - mp[m];
            while ( t-- > 0) {
                swap(result[cur], result[cur - 1]);
                cur--;
            }
        }
        return result;
    }
};
