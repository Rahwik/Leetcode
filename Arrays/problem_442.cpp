#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> flag;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                flag.push_back(abs(nums[i]));
            } else {
                nums[index] = -nums[index];
            }
        }
        return flag;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> val;
        vector<int> flag;
        for (int i = 0; i < nums.size(); i++) {
            int check = val.size();
            val.insert(nums[i]);
            if (check == val.size()) {
                flag.push_back(nums[i]);
            }
        }
        return flag;
    }
};