#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ai[100005];
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            ai[i] = a;
        }
        // for element i
        //    we want to perform operation n - ai[i] + 1 on it
        for(int i =0; i < n; i++) {
            // operation i
            for(int j = 0; j < n; j++) {
                if(i == n - ai[j]) {
                    cout << j + 1 << " ";
                    break;
                }
            }
        }
        // for every suffix we want to add so that it gets to n-1
        // 6 11 14 18 20
        //
        // each operation doesn't change the number of inversions in the suffix
        // only changes the number of inversions between the suffix and the prefix
        // if the suffix is the whole array, then nothing changes
        // if the suffix is the last element, then little changes
        // we just need to know which value to search for binary searchwise
        //
    }
}
