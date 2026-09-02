#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanMap = {
            {'I', 1},   {'V', 5},   {'X', 10},
            {'L', 50},  {'C', 100}, {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int currentVal = romanMap[s[i]];
            
            if (i < n - 1 && currentVal < romanMap[s[i + 1]]) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }
        return total;
    }
};