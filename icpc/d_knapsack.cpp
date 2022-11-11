#include <bits/stdc++.h>

using namespace std;

#define int long long
struct Obj {
    int w, v;
};
int dp[100005][105];
int32_t main() {
    int n,w;
    cin >> n >> w;
    vector<Obj> objs;
    for(int i =0; i < n; i++) {
        int wi, vi;
        cin >> wi >> vi;
        objs.push_back(Obj{wi,vi});
    }
    sort(objs.begin(), objs.end(), [](Obj const& a, Obj const& b) {
            return a.w < b.w;
        });
    // dp[i] stores the best cost we can get if the knapsack can store weight i
    for(int c =0; c <=w;c++) {
        for(int o = 1;o<=n;o++) {
            // capacity c, first n weights
            // the question is, do we use this weight?
            // if we don't, dp[c][o] = dp[c][o -1]
            // if we do, dp[c][o] = dp[c - obj.w][o - 1]
            Obj obj = objs[o - 1];
            if(o == 0) {
                // use 0 weights
                dp[c][o] = 0;
                continue;
            } else if(c < obj.w) {
                // can't even use this weight
                dp[c][o] = dp[c][o - 1];
                continue;
            }
            dp[c][o] = max(dp[c][o - 1], dp[c - obj.w][o - 1] + obj.v);
        }
    }
    cout << dp[w][n];
}

