#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e;
	//DSU(int N) { e = vector<int>(N, -1); }

	void init(int N) {
		e = vector<int>(N, -1);
	}

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
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<DSU> time(m + 1);
	time[0].init(n);

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		time[i] = time[i - 1];
		time[i].unite(a, b);
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		if (!time[m].same_set(a, b)) {
			cout << -1 << endl;
			continue;
		}


	}
}
