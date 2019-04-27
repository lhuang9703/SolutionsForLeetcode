# number : 849

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int length = seats.size();
        int result = 0;
        int *scan = new int[length];
        int count = 20000;
        for (int i = 0; i < length; i++) {
            if (seats[i] == 1) {
                count = 0;
            }
            else {
                scan[i] = ++count;
            }
        }
        count = 20000;
        for (int i = length - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                count = 0;
            }
            else {
                scan[i] = min(scan[i], ++count);
                if (scan[i] > result)
                    result = scan[i];
            }
        }
        return result;
    }
};
