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

vector<int> p;
vector<bool> vis;
int djsets;

void dfs(int x, DSU &uf) {
	vis[x] = 1;
	
	if (!vis[p[x]]) {
		if (uf.unite(x, p[x])) {
			djsets--;
		}
		dfs(p[x], uf);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		djsets = n;
		
		p.resize(n + 1);
		vis.resize(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> p[i];
			p[i]--;
		}

		DSU uf(n);

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i, uf);
			}
		}

		cout << djsets << endl;
		int ans = INT_MAX;
		for (int i = 0; i < n - 1; i++) {
			int ps = djsets - 1;

			if (uf.same_set(i, i + 1)) {
				ps = djsets + 1;
			}

			ans = min(ans, ps);
		}

		cout << ans << endl;
		cout << "-----" << endl;
	}
}
