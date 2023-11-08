#include <bits/stdc++.h>

using namespace std;

bool visited[101];

struct UF
{
    vector<int> par;

    UF(int n)
    {
        par = vector<int>(n, -1);
    }

    int get(int x)
    {
        return par[x] < 0 ? x : par[x] = get(par[x]);
    }

    bool check(int a, int b)
    {
        return get(a) == get(b);
    }

    int size(int x)
    {
        return -par[get(x)];
    }

    bool unify(int x, int y)
    {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
};

vector<pair<int, int> > mtree[101];\

int ans = 0;

void dfs(int n, int cost) {
    visited[n] = 1;
    ans += cost;

    for (int i = 0; i < mtree[n].size(); i++) {
        if (!visited[mtree[n][i].first]) {
            dfs(mtree[n][i].first, cost + mtree[n][i].second);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // unordered_set<string> langs;
    vector<pair<int, pair<int, int> > > edges;

    unordered_map<string, int> rename;

    for (int i = 0; i < n; i++)
    {
        string lang;
        cin >> lang;

        rename[lang] = i + 1;
    }

    for (int i = 0; i < m; i++)
    {
        string a, b;
        int cost;
        cin >> a >> b >> cost;
        edges.push_back(make_pair(cost, make_pair(rename[a], rename[b])));
    }

    sort(edges.begin(), edges.end());

    UF union_find(n + 1);

    int added = 0;

    memset(mtree, 0, sizeof(mtree));

    for (int i = 0; i < m; i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        // cout << cost << " " << a << " " << b << endl;
        // cout << union_find.check(a, b) << endl;

        if (!union_find.check(a, b)) {
            // cout << "added" << endl;
            added++;
            union_find.unify(a, b);
            mtree[a].push_back(make_pair(b, cost));
            mtree[b].push_back(make_pair(a, cost));
        }

        if (added == n) {
            break;
        }
    }

    if (added != n) {
        cout << "Impossible" << endl;
    }
    else {
        memset(visited, 0, sizeof(visited));

        dfs(0, 0);

        cout << ans << endl;
    }
}