class Solution
{
public:
    void setZeroes(vector<vector<int>> &m)
    {
        int r = m.size(), c = m[0].size();
        bool fr = false, fc = false;

        for (int i = 0; i < r; ++i)
        {
            if (m[i][0] == 0)
                fc = true;
        }
        for (int j = 0; j < c; ++j)
        {
            if (m[0][j] == 0)
                fr = true;
        }
        for (int i = 1; i < r; ++i)
        {
            for (int j = 1; j < c; ++j)
            {
                if (m[i][j] == 0)
                {
                    m[i][0] = 0;
                    m[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < r; ++i)
        {
            for (int j = 1; j < c; ++j)
            {
                if (m[i][0] == 0 || m[0][j] == 0)
                {
                    m[i][j] = 0;
                }
            }
        }
        if (fc)
        {
            for (int i = 0; i < r; ++i)
                m[i][0] = 0;
        }
        if (fr)
        {
            for (int j = 0; j < c; ++j)
                m[0][j] = 0;
        }
    }
};
