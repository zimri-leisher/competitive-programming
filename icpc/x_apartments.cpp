#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ai(n);
    vector<int> bi(m);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ai[i] = a;
    }
    for (int t = 0; t < m; t++) {
        int b;
        cin >> b;
        bi[t] = b;
    }
    // a + n
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());
    int c = 0;
    int r = 0;
    int p = 0;
    while (p < n && r < m) {
        int a = ai[p];
        int b = bi[r];
        if (a - b < -k) {
            // a is smaller
            p++;
        } else if (a - b > k) {
            // b is smaller
            r++;
        } else {
            c++;
            p++;
            r++;
        }
    }
    cout << c << endl;
}