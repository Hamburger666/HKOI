#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M;
string S, P;
ll nsp[2000][3];

ll ep(char a) {
    if (a == 'B') {
        return 0;
    } else if (a == 'W') {
        return 1;
    } else if (a == 'G') {
        return 2;
    } else {
        throw runtime_error("");
    }
}

vector<ll> other(ll n) {
    vector<ll> re;
    if (n == 0) {
        re.push_back(1);
        re.push_back(2);
    } else if (n == 1) {
        re.push_back(0);
        re.push_back(2);
    } else if (n == 2) {
        re.push_back(0);
        re.push_back(1);
    } else {
        throw runtime_error("");
    }
    return re;
}

ll next(ll i) {
    i++;
    if (i == M) {
        i = 0;
    }
    return i;
}

ll cp(ll n) {
    if (n >= M) {
        n -= M;
    }
    return n;
}


int main() {
    cin >> N;
    cin >> S;
    cin >> M;
    cin >> P;
    ll ic = 0;
    forn(i, M) {
        forn(u, 3) {
            nsp[i][u] = 0;
        }
    }
    forn(i, N) {
        nsp[ic][ep(S[i])]++;
        ic = next(ic);
    }
    ll minD = N;
    forn(i, M) {
        ll c = 0;
        forn(j, M) {
            for (ll u : other(ep(P[cp(j + i)]))) {
                c += nsp[j][u];
            }
        }
        minD = min(minD, c);
    }
    cout << minD << endl;
}