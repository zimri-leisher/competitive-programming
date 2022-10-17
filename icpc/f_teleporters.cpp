#include <bits/stdc++.h>

using namespace std;

int cost(int d, int breaks) {
    d = d * d;
    return d / (breaks + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> ais;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ais.push_back(a);
    }
    int m;
    cin >> m;
    // want to get to final teleporter
    // cost = (a_x - a_y)^2
    // max energy=m
    // you can add teleporters
    // min of how many you have to add
    // they should probably end up distributed evenly

    // as the energy increases, we can add fewer teleporters
    // teleporters every 1 distance unit, can remove middle teleporter
    // binary search for the optimal number
    // number of teleporters is valid if.... ??
    // maybe we have to greedy based on number of teleporters? and the binary search this number of teleporters?
    // given n teleporters, can we make it?
    // place teleporter in largest available space

    // greedy. we never have to break a new space with more than one teleporter
    // we want to run greedy until the energy usage is less than m
    int e = 0;
    int l = 0;
    vector<int> bis;
    for(auto& ai : ais) {
        e += (l - ai) * (l - ai);
        l = ai;
    }
    while(e > m) {
        // choose next best spot for teleporter
        // we can either break a new interval or an interval that has already been broken
        // we want to choose the one which has the biggest energy usage decrease
        // energy usage decrease of breaking existing interval = old - new
        // divide into pieces, square each piece
        //
        // old  = (distance / (n in interval + 1)) ^ 2 * n in interval
        // new = (distance / (n in interval + 1) ^ 2 * (n in interval + 1)
    }
    cout << e << endl;
}
