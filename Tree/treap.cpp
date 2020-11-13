#include<bits/stdc++.h>

using namespace std;

#define FTB(i,a,b) for(LL i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(LL i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(LL i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(LL i=a,_b=b;i>_b;i--)
#define endl "\n"
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define debug cout<<"VL\n";
#define coYES cout<<"YES\n";
#define coNO cout<<"NO\n";
#define coyes cout<<"yes\n";
#define cono cout<<"no\n";
#define coYes cout<<"Yes\n";
#define coNo cout<<"No\n";
#define PI 3.1415926535897
#define lbnd(f,s,gt) lower_bound(f,s,gt)
#define ubnd(f,s,gt) upper_bound(f,s,gt)
#define y1 aghksdmlsjdfjavljvlckdfmg
#define lamtron(n) fixed<<setprecision(n)
#define ALL(s) s.begin(),s.end()
#define ONLINE_JUDGE gshysrthrrthbd

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> inline T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

typedef long long ll;



ll n, l, r, sum;

struct node {
    ll val, cnt = 1, prio;
    node *lef = NULL, *rig = NULL;
    // cnt la so con cua cay
    node(ll val): val(val), prio(rand()) {};
};


node *find(node *root, int key) {
    if (!root) return nullptr;
    if (key > root->val) return find(root->rig, key);
    if (key < root->val) return find(root->lef, key);
    return root;
}

ll get(node *a) {
    return a ? a->cnt : 0;
}

node* rotate_righ(node *root) {
    node *a = root->lef, *b = a->rig;
    a->rig = root;
    root->lef = b;
    ll tmp = root->cnt;
    root->cnt = tmp - a->cnt + get(b);
    a->cnt = tmp;
    return a;
}

node* rotate_left(node *root) {
    node *a = root->rig, *b = a->lef;
    a->lef = root;
    root->rig = b;
    ll tmp = root->cnt;
    root->cnt = tmp - a->cnt + get(b);
    a->cnt = tmp;
    return a;
}

node* ins(node *root, ll val) {
    if (!root) return new node(val);
    root->cnt++;
    if (val > root->val) {
        root->rig = ins(root->rig, val);
        if (root->prio < root->rig->prio) root = rotate_left(root);
    }
    else if (val < root->val) {
        root->lef = ins(root->lef, val);
        if (root->prio < root->lef->prio) root = rotate_righ(root);
    }
    return root;
}

ll get_less(node *a, ll val) {
    if (!a) return 0;
    if (val == a->val) return get(a->lef);
    if (val < a->val) return get_less(a->lef, val);
    return a->cnt - get(a->rig) + get_less(a->rig, val);
}


void Solve() {
    srand(time(NULL));
    cin >> n >> l >> r;
    ll res = 0;
    node *root = NULL;
    root = ins(root, 0);
    while (n--) {
        ll x; cin >> x;
        sum += x;
        res += get_less(root, sum - l + 1) - get_less(root, sum - r);
        root = ins(root, sum);
    }
    cout << res;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

//    freopen("1.inp","r",stdin);
//    freopen("1.out","w",stdout);


    int Test_numbers = 1;
//    cin>>Test_numbers;

    while (Test_numbers--) Solve();

    return 0;
}


