#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

// Set up Red-Black Tree
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_pair_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Ordered_set
    ordered_set<int> X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    // Element at index
    cout << *X.find_by_order(1) << endl;            // 2
    cout << (end(X) == X.find_by_order(6)) << endl; // true

    // Find index of an element
    cout << X.order_of_key(-5) << endl;  // 0
    cout << X.order_of_key(1) << endl;   // 0
    cout << X.order_of_key(3) << endl;   // 2
    cout << X.order_of_key(4) << endl;   // 2
    cout << X.order_of_key(400) << endl; // 5

    int t = 0;

    ordered_pair_set me;
    me.insert({10, t++});
    cout << me.find_by_order(0)->first << endl;
    me.erase(me.lower_bound({10, 0}));
    cout << me.order_of_key({10, 0}) << "\n";

    return 0;
}