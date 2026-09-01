#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> charIndex(256, -1); 
        int maxLength = 0;
        int left = 0; 
        for (int right = 0; right < s.length(); ++right) {
           
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;

            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};