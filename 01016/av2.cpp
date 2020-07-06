#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll mdm[100000];
bool mdmb[100000];
ll diamonds[100000];
ll N;

ll kadane(ll v) {
    ll re;
    if (v == -1) {
        re = 0;
    } else {
        if (!mdmb[v]) {
            mdm[v] = max(kadane(v-1) + diamonds[v], diamonds[v]);
            mdmb[v] = true;
        }
        re = mdm[v];
    }
    return re;
}

int main() {
    cin >> N;
    forn (i, N) {
        cin >> diamonds[i];
    }
    ll sumV = 0;
    forn (i, N) {
        sumV += diamonds[i];
    }
    ll maxV = 0;
    forn (i, N) {
        if (kadane(i) > maxV) {
            maxV = kadane(i);
        }
    }
    // flip and reset
    forn(i, N) {
        diamonds[i] = -diamonds[i];
    }
    forn(i, N) {
        mdmb[i] = false;
    }

    ll minV = 0;
    forn (i, N) {
        if (kadane(i) > minV) {
            minV = kadane(i);
        }
    }



    cout << max(maxV, sumV + minV) << endl;
}