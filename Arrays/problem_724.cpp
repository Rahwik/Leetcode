class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int tSum = 0, lSum = 0;
        for (int num : nums)
        {
            tSum += num;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (lSum == tSum - lSum - nums[i])
            {
                return i;
            }
            lSum += nums[i];
        }
        return -1;
    }
};
