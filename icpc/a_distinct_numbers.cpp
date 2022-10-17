
#include <bits/stdc++.h>

using namespace std;


int32_t main() {

    int n;
    cin >> n;
    vector<int> ai(n);
    for(int i =0; i< n; i++) {
        int a;
        cin >> a;
        ai[i] = a;
//        cout << "test" << endl;
    }
    sort(ai.begin(), ai.end());
    int d = 1;
    int last = ai[0];
    for(int i =1; i < n; i++) {
        if(ai[i] != last) {
            d++;
        }
        last = ai[i];
//        cout << "test2" << endl;
    }
    cout << d;
}