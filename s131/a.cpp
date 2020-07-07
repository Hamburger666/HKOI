#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N;
ll ns[2][100];
ll gcd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int main() {
    forn(u, 2) {
        forn(i, 100) {
            ns[u][i] = 0;
        }
    }

    cin >> N;
    forn(u, 2) {
        forn(i, N) {
            ll n;
            cin >> n;
            ns[u][n]++;
        }
    }
    ll maxD = -1;
    for (ll k = 9999; k >= 1; k--) {
        ll need[100];
        forn(i, 100) {
            need[i] = 0;
        }
        forn (i, 100) {
            ll match = k - (i * 100 % k);
            if (match == k) {
                match = 0;
            }
            ll c = 0;
            if (match < 100) {
                need[match] += ns[0][i];
                match += k;
            }
        }
        ll nscat[100] = {0};
        forn(i, k) {
            for (ll j = i; j < 100; j += k) {
                nscat[i] += ns[1][j];
            }
        }
        bool ok = true;
        forn(i, 100) {
            ok &= need[i] == nscat[i];
        }
        if (ok) {
            maxD = k;
            break;
        }
    }
    cout << maxD << endl;
    forn(i, 100) {
        ll match = maxD - (i * 100 % maxD);
        if (match == maxD) {
            match = 0;
        } 
        forn(j, ns[0][i]) {
            while(match < 100 && !ns[1][match]) {
                match += maxD;
            }
            cout << i * 100 + match << endl;
            ns[1][match]--;
            while(match < 100 && !ns[1][match]) {
                match += maxD;
            }
        }
    }
}