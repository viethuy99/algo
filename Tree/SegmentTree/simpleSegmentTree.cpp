const int maxn = 1e5;

struct SimpleSegmentTree
{
    int n;
    int t[2 * maxn];

    void build()
    {
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    /**
     * *Set value at position p
    */
    void setValueAtPositionP(int p, int value)
    {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    /**
     * * Sum on interval [l, r)
     * 
    */
    int sumOnInterval(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }

    /**
     * * Add a value to all element in interval [l,r)
    */
    void addToInterval(int l, int r, int value)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                t[l++] += value;
            if (r & 1)
                t[--r] += value;
        }
    }

    /**
     * * Get value at position p
    */
    int getValueAtPosition(int p)
    {
        int res = 0;
        for (p += n; p > 0; p >>= 1)
            res += t[p];
        return res;
    }

    /**
     * * 
    */
    void push()
    {
        for (int i = 1; i < n; ++i)
        {
            t[i << 1] += t[i];
            t[i << 1 | 1] += t[i];
            t[i] = 0;
        }
    }
};
