class Solution
{
public:
    int subarraysDivByK(vector<int> &A, int k)
    {

        int n = A.size(), i = 0, S = 0, cnt = 0;
        vector<int> m(k, 0);
        m[0]++;

        for (int i = 0; i < n; i++)
        {
            S += A[i];
            int r = (S % k + k) % k;
            cnt += m[r];
            m[r]++;
        }

        return cnt;
    }
};