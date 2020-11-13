#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3+100;

int par[maxn][30], h[maxn], ufr[maxn];
int n, m, cnt = 0;
vector <int> e[maxn];

void dfs(int u, int p)
{
    par[u][0] = p;
    h[u] = h[p]+1;
    ufr[u] = cnt;
    for (auto v : e[u])
    {
        if (v == p || ufr[v])
            continue;
        dfs(v, u);
    }
    return ;
}

void rmq()
{
    for (int i = 1; i <= 22; i++)
    {
        for (int j = 1; j <= n; j++)
            par[j][i] = par[par[j][i-1]][i-1];
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i] == 0)
        {
            cnt ++;
            dfs(i, i);
        }
    }
    rmq();
}

int getpar(int u, int hi)
{
    for (int i = 22; i >= 0; i--)
        if ((hi >> i)&1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    u = getpar(u, h[u] - h[v]);
    if (u == v)
    {
        return v;
    }
    for (int i = 22; i >= 0; i--)
    {
        if (par[v][i] != par[u][i])
        {
            v = par[v][i];
            u = par[u][i];
        }
    }
    return  par[u][0];
}
