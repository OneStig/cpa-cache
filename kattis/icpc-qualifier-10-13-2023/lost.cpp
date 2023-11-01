#include <bits/stdc++.h>

using namespace std;

int visited[101];

pair<int, int> mcost[101];

// vector<pair<int, int> > mtree[101];

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

int main()
{
    int n, m;
    cin >> n >> m;

    // vector<pair<int, pair<int, int>>> edges;

    unordered_map<string, int> rename;

    vector<pair<int, int> > adj[101];

    for (int i = 0; i < n; i++)
    {
        string lang;
        cin >> lang;

        rename[lang] = i + 1;
        mcost[i + 1] = make_pair(INT_MAX, INT_MAX);
    }

    mcost[0] = make_pair(0, 0);

    UF union_find(n + 1);

    for (int i = 0; i < m; i++)
    {
        string a, b;
        int cost;
        cin >> a >> b >> cost;

        union_find.unify(rename[a], rename[b]);

        adj[rename[a]].push_back(make_pair(rename[b], cost));
        adj[rename[b]].push_back(make_pair(rename[a], cost));
        // edges.push_back(make_pair(cost, make_pair(rename[a], rename[b])));
    }

    if (union_find.size(0) != n + 1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        int ans = 0;
        memset(visited, 0, sizeof(visited));

        list<int> queue;

        visited[0] = 1;
        queue.push_back(0);

        while (!queue.empty())
        {
            int cur = queue.front();
            ans += mcost[cur].first;

            queue.pop_front();

            for (int i = 0; i < adj[cur].size(); i++)
            {
                int vt = adj[cur][i].first;

                if (mcost[cur].second + 1 < mcost[vt].second) {
                    mcost[vt].second = mcost[cur].second + 1;
                    mcost[vt].first = adj[cur][i].second;
                }
                else if (mcost[cur].second + 1 == mcost[vt].second) {
                    mcost[vt].first = min(mcost[vt].first, adj[cur][i].second);
                }

                if (!visited[vt])
                {
                    visited[vt] = 1;
                    queue.push_back(vt);
                }
            }
        }

        cout << ans << endl;
    }
}