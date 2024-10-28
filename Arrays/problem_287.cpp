#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> val;
        for (int i = 0; i < nums.size(); i++) {
            int check = val.size();
            val.insert(nums[i]);
            if (check == val.size()) {
                return nums[i];
            }
        }
        return -1;
    }
};
