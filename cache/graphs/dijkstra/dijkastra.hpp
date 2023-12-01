#include <bits/stdc++.h>
using namespace std;

/// begin
struct Dijkstra {
	using Cost = long long;
	using T = pair<int, Cost>;
	int N;
	vector<Cost> costs;
	vector<vector<T>> adj;
	priority_queue<T, vector<T>, greater<T>> pq;

	void init(int n) {
		N = n;
		costs.resize(n, numeric_limits<Cost>::max());
		adj.resize(n);
	}

	void edge(int a, int b, Cost cost) {
		adj[a].push_back({b, cost});
		adj[b].push_back({a, cost});
	}

	void process(int x) {
		pq.push({0, x});

		while (pq.size()) {
			T cur = pq.top()

			for (int i = 0; i < adj[cur.first].size(); i++) {

			}

			pq.pop();
		}
	}
};
