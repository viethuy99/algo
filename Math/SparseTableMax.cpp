

typedef long long ll;

struct SparseTableMax {
	int n, ma[200005][22];
	SparseTableMax() {

	}
	SparseTableMax(ll _n, ll a[]) {
		n = _n;
		for (int i = 1; i <= n; i++) ma[i][0] = a[i];
		for (int deg = 1; deg <= 20; deg++) {
			for (int i = 1; i <= n; i++) {
				ma[i][deg] = ma[i][deg - 1];
				if (i + (1 << (deg - 1)) <= n)
					ma[i][deg] = max(ma[i][deg], ma[i + (1 << (deg - 1))][deg - 1]);
			}
		}
	}

	ll getMax(ll i, ll j) {
		ll bac = log2(j - i + 1);
		return max(ma[i][bac], ma[j - (1 << bac) + 1][bac]);
	}
} STM;

