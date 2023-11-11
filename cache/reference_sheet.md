CPA Cache Reference Sheet
=========================

**Table of Contents**
- [1. geometry](#1-geometry)
- [2. graphs](#2-graphs)
	- [2.1 Disjoint Set Union](#21-disjoint-set-union)
- [3. range](#3-range)
	- [3.1 Segment Tree](#31-segment-tree)
## 1. geometry

## 2. graphs

#### 2.1 Disjoint Set Union

Some information about disjoint set unions

```cpp
struct DSU {
	vector<int> e;

	void init(int n) {
		e = vector<int>(n, -1);
	}

	int find(int x) {
		return (e[x] < 0 ? x : e[x] = find(e[x]));
	}

	bool unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) {
			return false;
		}

		if (e[a] > e[b]) {
			swap(a, b);
		}

		e[a] += e[b];
		e[b] = a;

		return true;
	}
	
	int size(int x) {
		return -e[find(x)];
	}

	bool is_same(int a, int b) {
		return find(a) == find(b);
	}
};

```
## 3. range

#### 3.1 Segment Tree

This is a segment tree

```cpp
struct SegTree {
	int a;
};

```
