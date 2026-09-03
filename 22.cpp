#include <vector>
#include <string>

class Solution {
private:
    void backtrack(int open, int close, int n, std::string current, std::vector<std::string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }
        if (close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(0, 0, n, "", result);
        return result;
    }
};