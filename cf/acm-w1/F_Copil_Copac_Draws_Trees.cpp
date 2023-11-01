#include <bits/stdc++.h>

using namespace std;

int visited[200000];
int max_layer;

int main() {
    int t;
    cin >> t;

    while (t--) {
        memset(visited, 0, sizeof(visited));
        int n;
        vector<int> tree[n];

        max_layer = 0;

        cin >> n;

        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        
    }
}

int bfs() {

}