#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

unordered_map<string, pair<bool, pair<unordered_set<string>, unordered_set<string> > > > compiled;
unordered_map<string, unordered_set<string> > isa_graph;

void traverse(string cl) {
	unordered_set<string> isa, hasa;
	auto cur = compiled[cl];
	if (!cur.first) {
		isa = cur.second.first;
		hasa = cur.second.second;
	}

	isa.insert(cl);

	for (auto i = cur.second.first.begin(); i != cur.second.first.end(); i++) {
		auto child = *i;

		compiled[child].second.first.insert(isa.begin(), isa.end());
		compiled[child].second.second.insert(hasa.begin(), hasa.end());

		traverse(child);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	unordered_set<string> empty;

	for (int i = 0; i < n; i++) {
		string a, rel, b;
		cin >> a >> rel >> b;

		if (compiled.find(a) == compiled.end()) {
			compiled.insert(make_pair(a, make_pair(true, make_pair(empty, empty))));
		}

		if (compiled.find(b) == compiled.end()) {
			compiled.insert(make_pair(b, make_pair(true, make_pair(empty, empty))));
		}

		if (rel == "is-a") {
			isa_graph[b].insert(a);
			compiled[b].first = false;
		}
		else {
			compiled[a].second.second.insert(b);
		}
	}

	for (auto i = compiled.begin(); i != compiled.end(); i++) {
		auto cur = *i;

		if (cur.second.first) {
			traverse(cur.first);
		}
	}

	for (int i = 0; i < m; i++) {
		string a, rel, b;
		cin >> a >> rel >> b;

		cout << "Query " << (i + 1) << ": ";

		if (rel == "is-a") {
			if (a == b) {
				cout << "true" << endl;
				continue;
			}	

			cout << (compiled[a].second.first.find(b) == compiled[a].second.first.end() ? "false" : "true") << endl;
		}
		else {
			
		}
	}
}
