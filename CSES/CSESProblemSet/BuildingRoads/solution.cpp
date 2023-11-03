#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DSU uf(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		uf.unite(a, b);
	}

	int ans = 0;
	vector<pair<int, int> > bridges;
	for (int i = 1; i < n; i++) {
		if (!uf.same_set(i, i - 1)) {
			ans++;
			bridges.push_back(make_pair(i, i + 1));
			uf.unite(i, i - 1);
		}
	}

	cout << ans << endl;
	for (int i = 0; i < bridges.size(); i++) {
		cout << bridges[i].first << " " << bridges[i].second << endl;
	}
}
