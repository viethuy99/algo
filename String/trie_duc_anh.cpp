#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

const long long maxn = 3000100, mod = 1337377;

struct node
{
    int next[40], finish = 0;
} tree[maxn];

string s;
int n;
long long f[maxn];

void add(string t)
{
    int now = 0;
    for (int i = t.size() - 1; i >= 0; i--)
    {
        if (tree[now].next[t[i] - 'a'] == 0)
            tree[now].next[t[i] - 'a'] = ++cnt;
        now = tree[now].next[t[i] - 'a'];
    }
    tree[now].finish = 1;
}