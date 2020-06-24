#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
typedef long long ll;
using namespace std;

ll X, Y, K;
bool g[3001][3001] = {0};
bool gt[3001][3001] = {0};
void printg() {
    forn(_, Y+1) {
        ll y = Y - _;
        forn(x, X+1) {
            cout << g[x][y] << " ";
        }
        cout << endl;
    }
}
int main() {
    cin >> X >> Y >> K;
    if (K == 0) {
        ll re = 0;
        forn(i, min(X, Y)) {
            re += (X - i) * (Y - i);
        }
        cout << re << endl;
        return 0;
    } else {
        forn(i, K) {
            ll x, y;
            cin >> x >> y;
            g[x][y] = true;
        }
        ll re = 0;
        form(i, min(X, Y)) {
            forn(x0, X-i+1) {
                forn(y0, Y - i+1) {
                    forn(i, X+1) forn(k, Y+1) {
                        gt[i][k] = false;
                    }
                    ll cn = 0;
                    forn(l, i+1) {
                        if (g[x0 + l][y0 + l] && !gt[x0 + l][y0 + l]) {
                            gt[x0 + l][y0 + l] = true;
                            cn++;
                        }
                        if (g[x0 + l][y0 + i - l] && !gt[x0 + l][y0 + i - l]) {
                            gt[x0 + l][y0 + i - l] = true;
                            cn++;
                        }
                    }
                    if (cn == K) {
                        re++;
                    }
                }
            }
        }
        cout << re << endl;
    }
}