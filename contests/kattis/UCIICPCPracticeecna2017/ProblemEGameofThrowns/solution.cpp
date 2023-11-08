#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> ans_stack;
	ans_stack.push_back(0);

	int cur = 0;
	while (k--) {
		string cmd;
		cin >> cmd;

		if (cmd == "undo") {
			int undos;
			cin >> undos;
			
			cur = *(ans_stack.end() - undos - 1);
			ans_stack.resize(ans_stack.size() - undos);
		}
		else {
			int c = stoi(cmd);
			cur += c;

			if (cur < 0) {
				cur += n * 10000;
			}

			cur %= n;	
			ans_stack.push_back(cur);
		}
	}

	cout << cur << endl;
}
