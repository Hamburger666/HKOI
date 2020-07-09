#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N;
ll ns[5000];
ll nsb[5000];
ll next(ll i) {
    i++;
    if (i == N) {
        i = 0;
    }
    return i;
}
int main() {
    cin >> N;
    forn(i, N) {
        cin >> ns[i];
        ns[i]--;
    }
    ll p[5000] = {0};
    forn(i, N) {
        forn(j, i) {
            p[i] += (ns[j] > ns[i]);
        }
    }
    ll minC = N*N;
    forn(cutI, N) {
        ll ic = 0;
        ll i = cutI;
        forn(ic, N) {
            nsb[ic] = ns[i];
            i = next(i);
        }
        ll pos[5000];
        forn(i, N) {
            pos[nsb[i]] = i;
        }
        ll c = 0;
        forn(i, N) {
            c += p[i];
        }
        for (ll i = N-1; i >= 0; i--) {
            ll changeI = pos[i];
            c = c + changeI - (N - changeI - 1);
            minC = min(c, minC);
        }
        ll pt[5000];
        ll moveV = nsb[0];
        forn(i, N-1) {
            if (nsb[i+1] < moveV) {
                pt[i] = p[i+1] - 1;
            } else {
                pt[i] = p[i+1];
            }
        }
        pt[N-1] = 0;
        forn(_, N-1) {
            ll i = _ +1;
            pt[N-1] += (nsb[i] > moveV);
        }
        forn(i, N) {
            p[i] = pt[i];
        }
    }
    cout << minC << endl;
}