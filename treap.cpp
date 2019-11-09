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
template<class T> inline T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

typedef double DB;
typedef long long LL;
typedef unsigned long long UL;
typedef long double LD;
typedef pair<LL,LL> II;
typedef vector<LL> VI;
typedef vector<II> VII;
typedef vector<bool> VB;

//tao node

struct Node {
    int key, priority;
    Node *left = nullptr, *right = nullptr;
    Node(int key) : key(key), priority(rand()) {}
};

// tim kiem
#define left root->left
#define right root->right

Node *find(Node *root, int key) {
    if (!root) return nullptr;
    if (key > root->key) return find(right, key);
    if (key < root->key) return find(left, key);
    return root;
}

//timcay

Node *rotate_right(Node *node) {
    Node *x = node->left, *t = x->right;
    x->right = node;
    node->left = t;
    return x;
}

Node *rotate_left(Node *node) {
    Node *x = node->right, *t = x->left;
    x->left = node;
    node->right = t;
    return x;
}

// chen
Node *insert(Node *root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) {
        left = insert(left, key);
        if (root->priority > left->priority)
            root = rotate_right(root);
    } else if (key > root->key) {
        right = insert(right, key);
        if (root->priority > right->priority)
            root = rotate_left(root);
    }
    return root;
}




int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	freopen("output.txt","w",stdout);
    #endif
    Node t;





	return 0;
}




