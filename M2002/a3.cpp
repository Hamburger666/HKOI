#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M, Q;
bool channels[10000][100];
ll costs[10000];
ll list2[20000][20] = {0}; ll ls[20000];
unordered_set<ll> movies[100];

void printL(ll *l, ll n) {
    forn(i, n) {
        cout << l[i] << " ";
    }
    cout << endl;
}

void printL(bool *l, ll n) {
    forn(i, n) {
        cout << l[i] << " ";
    }
    cout << endl;
}

void printL(vector<ll> l) {
    ll n = l.size();
    forn(i, n) {
        cout << l[i] << " ";
    }
    cout << endl;
}

void prints(unordered_set<ll> l) {
    cout << "printsing ";
    for (ll c : l) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> M >> Q;
    forn(i, N) {
        cin >> costs[i];
    }
    forn(i, N) {
        forn(j, M) {
            cin >> channels[i][j];
        }
    }
    forn(i, Q) {
        ll L;
        cin >> L;
        forn(k, L) {
            cin >> list2[i][k];
            list2[i][k]--;
        }
        ls[i] = L;
    }


    forn(cid, N) {
        forn(mid, M) {
            if (channels[cid][mid]) {
                movies[mid].insert(cid);
            }
        }
    }

    forn(lid, Q) {
        unordered_set<ll> goodChannels;
        forn(cid, N) {
            goodChannels.insert(cid);
        }
        forn(i, ls[lid]) {
            ll mid = list2[lid][i];
            vector<ll> newGoodChannels;
            // auto it = set_intersection(goodChannels.begin(), goodChannels.end(), movies[mid].begin(), movies[mid].end(), newGoodChannels.begin());
            for (ll cid : goodChannels) {
                if (!(movies[mid].empty() || movies[mid].find(cid) == movies[mid].end())) {
                    newGoodChannels.push_back(cid);
                }
            }

            // newGoodChannels.resize(it - newGoodChannels.begin());
            goodChannels.clear();
            for (ll cid : newGoodChannels) {
                goodChannels.insert(cid);
            }
        }
        ll lowCost = LONG_MAX;
        for (ll cid : goodChannels) {
            if (costs[cid] < lowCost) {
                lowCost = costs[cid];
            }
        }
        cout << (lowCost == LONG_MAX ? -1 : lowCost) << endl;
    }
}