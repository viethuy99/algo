
#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 100006
 
using namespace std;
int n, m, componentcount = 0, counter = 0;
int num[maxn], low[maxn], dd[maxn];
vector <int> e[maxn];
stack <int> s;
 
void dfs(int u)
{
    counter ++;
    num[u] = low[u] = counter;
    s.push(u);
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (dd[v])
            continue;
        if (num[v] != 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        int v;
        componentcount ++;
        do
        {
            v = s.top();
            s.pop();
            dd[v] = 1;
        } while (v!=u && !s.empty());
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        if (num[i] == 0)
            dfs(i);
    cout << componentcount;
    return 0;
}
 