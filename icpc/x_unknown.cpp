#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <sstream>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
typedef pair<ll, ll> pl;

void bfs(vector<pl> &g, vector<ll> &s, vector<ll> &balls, ll node) {
    if (node == 0) {
        return;
    }
    cout << node << endl;
    cout << "balls at" << balls[node] << endl;
    ll l = g[node].first;
    ll r = g[node].second;
    ll b = balls[node];
    if (b % 2 == 0) {
        balls[l] = b / 2 + balls[l];
        balls[r] = b / 2 + balls[r];
    } else {
        balls[l] = balls[node] / 2 + balls[l] + (s[node] == 'L');
        balls[r] = balls[node] / 2 + balls[r] + (s[node] == 'R');
    }
    bfs(g, s, balls, l);
    bfs(g, s, balls, r);
}

int mai4n() {
    ll n, m;
    cin >> n >> m;
    vector<pl> g;
    g.emplace_back(0,0);
    vector<ll> s;
    s.push_back(0);
    vector<ll> balls(n + 2, 0);
    for (ll i = 0; i < m; i++) {
        char c;
        ll a, b;
        cin >> c >> a >> b;
        g.emplace_back(a, b);
        s.push_back(c == 'R');
    }
    balls[1] = n;
    bfs(g, s, balls, 1);
    for(int i = 1; i <= m; i++) {
        int flips = balls[i] % 2;
        cout << "flips: " << flips << " at " << i << endl;
        cout << "originally " << s[i] << endl;
        cout << "now:";
        if(flips) {
            if(s[i]) {
                cout << 'L';
            } else {
                cout << 'R';
            }
        } else {
            if(s[i]) {
                cout << 'R';
            } else {
                cout << 'L';
            }
        }
        cout << endl;
    }
    cout << endl;
}