class hashString
{
public:
    vector<long long> h[3];
    vector<long long> base = {123, 117, 111};
    vector<long long> po[3];
    void set_string(string a)
    {
        for (int i = 0; i < base.size(); i++)
        {
            int len = a.length() + 1;
            h[i].resize(len);
            h[i][0] = 0;
            po[i].resize(len);
            po[i][0] = 1;
            for (int j = 0; j < a.length(); j++)
            {
                po[i][j + 1] = (po[i][j] * base[i]) % mod;
                h[i][j + 1] = (h[i][j] * base[i] + a[j]) % mod;
            }
        }
    }
    vector<long long> get_hash(int l, int r)
    {
        vector<long long> result;
        for (int i = 0; i < base.size(); i++)
        {
            long long res = (h[i][r + 1] - h[i][l] * po[i][r - l + 1] + mod * mod) % mod;
            result.push_back(res);
        }
        return result;
    }
};