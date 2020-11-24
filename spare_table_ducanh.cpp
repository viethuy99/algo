class spare_table
{

private:
    int table[maxn][30];
public:
    void build(int a[], int len, int ff(int, int))
    {
        memset(table, 0, sizeof(table));
        for (int i = 1; i <= len; i++)
            table[i][0] = a[i];
        for (int j = 1; (1<<j) <= len; j++)
        {
            for (int i = 1; i <= len; i++)
            {
                table[i][j] = ff(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    int get(int l, int r, int ff(int, int))
    {
        int j = log2(r-l+1);
        return ff(table[l][j], table[r-(1<<j)+1][j]);
    }

};