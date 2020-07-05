#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll; 

ll N;
ll diamonds[100000];
pair<ll, ll> mdm[100000]; // {sum, length}
bool mdmb[100000];

ll prev(ll i) {
    i--;
    if (i < 0) {
        i += N;
    }
    return i;
}


pll md(ll v, ll depth) { // return: {sum, length}
    pll re;
    if (depth == N) {
        re = make_pair(0, 0);
    } else {
        if (mdmb[v]) {
            re = mdm[v];
        } else {
            if (md(prev(v), depth+1).second == N) {
                re = md(prev(v), depth+1);
            } else{
                if (md(prev(v), depth+1).first > 0) {
                    mdm[v].first = md(prev(v), depth+1).first + diamonds[v];
                    mdm[v].second = md(prev(v), depth+1).second + 1;
                } else {
                    mdm[v].first = diamonds[v];
                    mdm[v].second = 1;
                }
                re = mdm[v];
            }
            if (depth == 0) {
                mdmb[v] = true;
            }
        }
    }
    return re;
}

int main() {
    cin >> N;
    forn(i, N) {
        cin >> diamonds[i];
    }
    ll maxD = 0;
    forn(i, N) {
        if (md(i, 0).first > maxD) {
            maxD = md(i, 0).first;
        }
    }
    cout << maxD << endl;
}