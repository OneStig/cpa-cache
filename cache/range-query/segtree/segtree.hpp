#include <bits/stdc++.h>

using namespace std;

/// begin
template <class T> struct SegTree {
	const T DEFAULT = 0;

	vector<T> segtree;
	int tree_n;

	SegTree(int tree_n) : tree_n(tree_n), segtree(tree_n * 2, DEFAULT) {}

	void set(int ind, T val) {
		ind += tree_n;
		segtree[ind] = val;

		while (ind > 1) {
			segtree[ind / 2] = segtree[ind] + segtree[ind ^ 1];
			ind /= 2;
		}
	}

	T sum(int start, int end) {
		T sum = DEFAULT;
		for (start += tree_n, end += tree_n; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum += segtree[start++]; }
			if (end % 2 == 1) { sum += segtree[--end]; }
		}
		return sum;
	}
};
