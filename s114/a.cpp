#include <iostream>
#include <algorithm>
#include <stdexcept>
#define forn(i, n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, C;
ll Nc;
ll ns[1000];
ll ns2[2][500];
ll rings1[1000];
ll rings2[2][500];
ll out[1000];

ll prev(ll i) {
    i--;
    if (i < 0) {
        i += Nc;
    }
    return i;
}

ll next(ll i) {
    i++;
    if (i >= Nc) {
        i -= Nc;
    }
    return i;
}

int main() {
    cin >> N >> C;
    forn(i, N) {
        cin >> ns[i];
    }
    sort(ns, ns + N);
    if (N % 2 == 0) {
        Nc = N / 2;
        forn(i, Nc) {
            ns2[0][i] = ns[i];
        }
        forn(i, Nc) {
            ns2[1][i] = ns[i + Nc];
        }
        forn(u, 2) {
            ll iLeft = prev(0);
            ll iRight = 0;
            forn(i, Nc) {
                if (i % 2 == 0) {
                    rings2[u][iRight] = ns2[u][i];
                    iRight = next(iRight);
                } else {
                    rings2[u][iLeft] = ns2[u][i];
                    iLeft = prev(iLeft);
                }
            }
        }
        ll ic = 0;
        forn(i, N) {
            if (i % 2 == 0) {
                out[i] = rings2[0][ic];
            } else {
                out[i] = rings2[1][ic];
                ic++;
            }
        }
    } else {
        Nc = N;
        ll iRight = 0; 
        ll iLeft = prev(0);
        forn(i, Nc) {
            if (i % 2 == 0) {
                rings1[iRight] = ns[i];
                iRight = next(iRight);
            } else {
                rings1[iLeft] = ns[i];
                iLeft = prev(iLeft);
            }
        }
        ll ic = 0;
        forn(i, N) {
            out[ic] = rings1[i];
            forn(_, 2) ic = next(ic);
        }
    }
    forn(i, N) {
        cout << out[i] << " ";
    }
    cout << endl;
}