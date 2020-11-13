#include <bits/stdc++.h>
#include <ext/rope>

using namespace __gnu_cxx; // For rope
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    /**
     *  Rope : this data structure can fastly insert arbitrary blocks of array to any position and erase them
    */

    rope<int> v; //use as usual STL container
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        v.push_back(i); //initialization
    int l, r;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        --l, --r;
        rope<int> cur = v.substr(l, r - l + 1);
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);
    }
    for (rope<int>::iterator it = v.mutable_begin(); it != v.mutable_end(); ++it)
        cout << *it << " ";
    return 0;
}