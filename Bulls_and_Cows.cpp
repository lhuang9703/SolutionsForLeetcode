# number : 299

class Solution {
public:
    string getHint(string secret, string guess) {
        int bullsCount = 0, cowsCount = 0;
        unordered_map<int, int> mpSecret, mpGuess;
        int len = (int)secret.size();
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                bullsCount++;
            }
            else {
                if (mpSecret.find(secret[i]) == mpSecret.end()) { mpSecret[secret[i]] = 1; }
                else { mpSecret[secret[i]] += 1; }
                if (mpGuess.find(guess[i]) == mpGuess.end()) { mpGuess[guess[i]] = 1; }
                else { mpGuess[guess[i]] += 1; }
            }
        }
        for (unordered_map<int, int>::iterator it = mpSecret.begin(); it != mpSecret.end(); it++) {
            if (mpGuess.find(it->first) != mpGuess.end()) {
                cowsCount += min(it->second, mpGuess[it->first]);
            }
        }
        return to_string(bullsCount) + "A" + to_string(cowsCount) + "B";
    }
};
