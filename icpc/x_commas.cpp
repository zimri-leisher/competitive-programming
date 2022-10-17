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

//https://open.kattis.com/problems/newfiber
// n - 1 new edges
// the question is where do you want to allocate these edges?
// each node has a "demand", more or less than this demand is bad
//

using namespace std;

struct Val {
    vector<string> values;
};

unordered_map<string, Val> m;

void bfs(unordered_map<string, bool> &t, const string &w) {
    t[w] = true;
    for (auto &val : m[w].values) {
        if (!t[val]) {
            bfs(t, val);
        }
    }
}

int main1() {
    // unordered map of word+side to adjacent word+side
    // for each word, add it's plus side to the minus side of the next word, if it doesn't contain period.
    // if it contains comma, add its plus side to a list of "truths"
    //
    string s;
    unordered_map<string, bool> t;
    char z;
    string l;
    vector<string> ws;
    while (cin >> s) {
        char c = s[s.length() - 1];
        string w = (c == ',' || c == '.') ? s.substr(0, s.length() - 1) : s;
        if (c == ',') {
            // if its a comma, its right is true and nexts left is true.
            t[w + '+'] = true;
        }
        if (!l.empty()) {
            if (z == ',') {
                t[w + '-'] = true;
            }
        }
        if (!l.empty()) {
            // if there was a previous string, add this left to its right
            auto &values = m[l + '+'].values;
            if (find(values.begin(), values.end(), w + '-') == values.end()) {
                values.push_back(w + '-');
                m[w + '-'].values.push_back(l + "+");
            }
        }
        if (c == '.') {
            l = "";
            z = '\0';
        } else {
            l = w;
            z = c;
        }
        if (c == '.') {
            ws.push_back(s);
        } else {
            ws.push_back(w);
        }
    }
//    for(auto& k : m) {
//        cout << k.first << " with:\n";
//        for(auto& e : k.second.values) {
//            cout << e << endl;
//        }
//    }
    for (auto &tr : t) {
        bfs(t, tr.first);
    }
    z = '\0';
    l = "";
    int i = 0;
    for (auto &w : ws) {
        char c = w[w.length() - 1];
        string h = (c == '.') ? w.substr(0, w.length() - 1) : w;
        if (z != '.' && t[h + '-'] && !t[l + '+']) {
            cout << ", " << h;
        } else {
            cout << h;
        }
        if (c != '.' && t[h + '+']) {
            cout << ", ";
        } else if (c == '.') {
            if (i == ws.size() - 1) {
                cout << ".";
            } else {
                cout << ". ";
            }
        } else {
            cout << " ";
        }
        l = h;
        z = c;
        i++;
    }
    cout << endl;
}

char ch(string &w) {
    if (w[w.length() - 1] == '.' || w[w.length() - 1] == ',') {
        return w[w.length() - 1];
    }
    return '\0';
}

string word(string &w) {
    if (ch(w) != '\0') {
        return w.substr(0, w.length() - 1);
    }
    return w;
}

void dfs(unordered_map<string, bool> &bt, unordered_map<string, bool> &et, unordered_map<string, vector<string>> &begin,
         unordered_map<string, vector<string>> &end, string &s) {
    for(auto& e : begin[s]) {
        if(!bt[e]) {
            bt[e] = true;
            dfs(bt,et,begin,end,e);
        }
    }
}

int hmain() {
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    string w;
    string l;
    char lc = '\0';
    unordered_map<string, vector<string>> begin;
    unordered_map<string, vector<string>> end;
    unordered_map<string, bool> bt;
    unordered_map<string, bool> et;
    while (ss >> w) {
        if (w.empty())
            continue;
        char c = ch(w);
        string wr = word(w);
        if (!l.empty()) {
            begin[wr].push_back(l);
            end[l].push_back(wr);
        }
        if (lc == ',') {
            bt[wr] = true;
            et[l] = true;
        }
        if (c != '.') {
            l = wr;
            lc = c;
        } else {
            l = "";
            lc = '\0';
        }
    }

}
