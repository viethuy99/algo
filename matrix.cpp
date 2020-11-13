

struct matrix {
	vector<vector<ll>> cong(vector<vector<ll>> a, vector<vector<ll>> b) {
		for (int i = 0; i < a.size(); i++) for (int j = 0; j < a[0].size(); j++) {
				a[i][j] += b[i][j];
			}
		return a;
	}

	vector<vector<ll>> tru(vector<vector<ll>> a, vector<vector<ll>> b) {
		for (int i = 0; i < a.size(); i++) for (int j = 0; j < a[0].size(); j++) {
				a[i][j] -= b[i][j];
			}
		return a;
	}

	vector<vector<ll>> nhan(vector<vector<ll>> a, vector<vector<ll>> b) {
		ll n, m, k;
		n = a.size(); m = b.size(); k = b[0].size();
		vector<vector<ll>> res(n, vector<ll>(k, 0));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int g = 0; g < k; g++) {
					res[i][g] += (a[i][j] * b[j][g]) % mod;
					res[i][g] %= mod;
				}
		return res;
	}

	vector<vector<ll>> qp(vector<vector<ll>> a, ll b) {
		if (b == 1) return a;
		if (b & 1) return nhan(a, qp(a, b - 1));
		return qp(nhan(a, a), b >> 1);
	}
} MT;