#include <bits/stdc++.h>

using namespace std;

/// begin
struct DSU {
	vector<int> e;

	void init(int n) { e = vector<int>(n, -1); }
	int find(int x) { return (e[x] < 0 ? x : e[x] = find(e[x])); }

	bool unite(int a, int b) {
		a = find(a), b = find(b);

		if (a == b)
			return false;

		if (e[a] > e[b])
			swap(a, b);

		e[a] += e[b];
		e[b] = a;

		return true;
	}
	
	int size(int x) { return -e[find(x)];	}

	bool is_same(int a, int b) { return find(a) == find(b); }
};
