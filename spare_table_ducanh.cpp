class spare_table
{

long long table[maxn][20];
public:
    void build(long long a[], long long len, long long ff(long long, long long))
    {
        memset(table, 0, sizeof(table));
        for (long long i = 1; i <= len; i++)
            table[i][0] = a[i];
        for (long long j = 1; (1<<j) <= len; j++)
        {
            for (long long i = 1; i + (1<<j)-1 <= len; i++)
            {
                table[i][j] = ff(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    long long get(long long l, long long r, long long ff(long long, long long))
    {
        long long j = log2(r-l+1);
        return ff(table[l][j], table[r-(1<<j)+1][j]);
    }

};

