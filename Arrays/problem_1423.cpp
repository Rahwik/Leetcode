#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if (k == n) {
            return total_sum; // If k equals the number of cards, take all of them.
        }
        
        int window_size = n - k;
        int current_sum = accumulate(cardPoints.begin(), cardPoints.begin() + window_size, 0);
        int min_subarray_sum = current_sum;
        
        for (int i = window_size; i < n; ++i) {
            current_sum += cardPoints[i] - cardPoints[i - window_size];
            min_subarray_sum = min(min_subarray_sum, current_sum);
        }
        
        return total_sum - min_subarray_sum;
    }
};
