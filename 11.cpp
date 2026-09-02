#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            max_water = std::max(max_water, h * w);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_water;
    }
};
#Time Complexity: $O(n)$ — The two pointers traverse the array of length $n$ once.
#Space Complexity: $O(1)$ — Only constant additional space is used.
