class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            int width = r - l;
            int minHeight = min(height[l], height[r]);
            res = max(res, width * minHeight);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return res;
    }
};
