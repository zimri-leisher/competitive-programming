#include <bits/stdc++.h>

using namespace std;
#define int long long
int fun(int n) {
    // number of vertices that will be in the clique
    // return number of edges that will be in the clique
    return (n * (n - 1)) / 2;
}

int bin(int l, int r, int n) {
    int ans = 0;
    while (l <= r) {
//        cout << "bin search with " << l << ", " << r << endl;
        int mid = (l + r) / 2;
//        cout << "mid: " << mid << endl;
        int bridges = n - mid - (mid==0);
        int edgesInClique = fun(mid);
//        cout << "bridges: " << bridges << ", edges in clique: " << edgesInClique << endl;
        if (edgesInClique > bridges) {
//            cout << "more edges in clique than bridges" << endl;
            // this means we have too few bridges, so we need to convert fewer edges into bridges
            edgesInClique = bridges;
            r = mid - 1;
            // invalid answer
        } else {
            // we have too many bridges, increase lower bound
//            cout << "too many bridges" << endl;
            l = mid + 1;
            // valid answer
        }
        ans = max(edgesInClique + bridges, ans);
    }
//    cout << "end result: " << l << endl;
    return ans;
}

int32_t main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        int b = bin(0, n - 1, n);
        cout << b << endl;
    }
}