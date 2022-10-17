#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    int ai[405];
    int opt[405][405];
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        ai[i] = a;
    }
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            cout << "calculating opt[" << l << "][" << r << "]\n";
            ll sum = 0;
            for (int i = l; i < r; i++) {
                sum += ai[i];
            }
            ll minCost = 400 * 10e10;
            for (int m = l + 1; m < r; m++) {
                cout << "trying opt[" << l << "][" << m << "] + opt[" << m << "][" << r << "]" << endl;
                minCost = min(minCost, opt[l][m] + opt[m][r] + sum);
            }
            cout << "min cost: " << minCost << endl;
            opt[l][r] = minCost;
        }
    }
    cout << opt[0][n];
    // dp. try every possible combination of joinings.
    // we want opt[x][len] = optimal for range x, x + len
    // ans = opt[0][n]
    // opt[x][0] = 0
    // opt[x][1] = ai[x]
    // opt[x][2] = ai[x] + ai[x + 1]
    // opt[x][3] = min(2 * opt[x][2] + ai[x + 2], 2 * opt[x + 1][2] + ai[x])
    //

    // do we just want to find the optimal spot to join?


    // for m in l until r
    //  cost = min(cost, opt[l][l + m] + opt[l + m + 1][r] + sum(l,r))
    //
    // for x in 0 until n
    //  for y in 0 to n
    //   cost = 0
    //   for j in 0 to n
    //    cost = min(cost, 2 * opt[0][j] + 2 * opt[j][n - j])
    //   opt[x][y] = cost
    // return opt[0][n]
}
