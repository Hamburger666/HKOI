#include <iostream>
#include <vector>
#include <algorithm>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll ns[500000];
pll carts[50000]; // {width, size}
ll outD[500000];
ll lastJ[1001] = {0};
bool possible;

int main() {
    cin >> N >> M;
    forn(i, N) {
        cin >> ns[i];
    }
    forn(i, M) {
        ll w, v;
        cin >> w >> v;
        carts[i] = make_pair(w, v);
    }
    possible = true;
    forn(i, N) {
        ll ok = false;
        for (ll j = lastJ[ns[i]]; j < M; j++) {
            if (carts[j].first >= ns[i] && carts[j].second - ns[i] >= 0) {
                carts[j].second -= ns[i];
                outD[i] = j;
                lastJ[ns[i]] = j;
                ok = true;
                break;
            }
        }
        if (!ok) {
            possible = false;
            break;
        }
    }
    if (possible) {
        forn(i, N) {
            cout << outD[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }
}