
#include <bits/stdc++.h>

using namespace std;
set<int> colors;
vector<int> g[300][300];
vector<int> marked(300);

void dfs(int u, int c) {
    for (auto &n: g[c][u]) {
        if (!marked[n]) {
            marked[n] = 1;
            dfs(n, c);
        }
    }
}

int query(int u, int v) {
    int t = 0;
    for (auto &c: colors) {
        dfs(u, c);
        if (marked[v]) {
            t++;
        }
        marked.assign(300, 0);
    }
    return t;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        colors.insert(c);
        g[c][a].push_back(b);
        g[c][b].push_back(a);
    }
    int q;
    cin >> q;
    for (int e = 0; e < q; e++) {
        int u, v;
        cin >> u >> v;
//        cout << "querying" << endl;
        cout << query(u, v) << endl;
    }
}
/*
4 5
1 2 1
1 2 2
2 3 1
2 3 3
2 4 3
1
1 2

 */