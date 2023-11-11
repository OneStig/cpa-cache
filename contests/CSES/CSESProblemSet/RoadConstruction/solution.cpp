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

	int ds = n;
	int largest = 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		if (uf.unite(a, b)) {
			ds--;
			largest = max(largest, uf.size(a));
		}
		cout << ds << " " << largest << endl;
	}
}
