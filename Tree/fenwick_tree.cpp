

struct fenwick_tree {
	long long fen[1000005], n;

	void set(int x, long long val) {
		while (x <= n) {
			fen[x] += val;
			x += (x & (-x));
		}
	}

	long long get(int x) {
		long long res = 0;
		while (x) {
			res += fen[x];
			x -= (x & (-x));
		}
		return res;
	}

	//get largest index that sum arr_1 -> arr_id less or equal val

	int getind(long long val) {
		int idx = 0, mask = n;
		while (mask && idx < n) {
			int t = idx + mask;
			if (val >= fen[t]) {
				idx = t;
				val -= fen[t];
			}
			mask >>= 1;
		}
		return idx;
	}
} FT;
