#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll pills[2000][10001];
ll maxX[2000];
ll N, M;

int main() {
    cin >> N >> M;
    forn(n, N) {
        forn(m, M) {
            ll x, y;
            cin >> x >> y;
            pills[n][y] = max(pills[n][y], x);
        }
    }
    double minD = 10000;
    for (ll k = 1; k < 10000; k++) {
        bool ok = true;
        ll sum = 0;
        forn(n, N) {
            maxX[n] = max(maxX[n], pills[n][k]);
            ok &= maxX[n] != 0;
            sum += maxX[n];
        }
        if (ok) {
            minD = min(minD, k / (double) sum);
        }
    }
    printf("%.8f\n", minD);
}
