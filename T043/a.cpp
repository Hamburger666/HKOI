#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, T;
ll rooms[50];
vector<ll> bombs[50];
ll mbbma[50001], mbbmb[50001], mbsma[50001], mbsmb[50001];


int main() {
    cin >> N >> T;
    forn(i, N) {
        ll L;
        cin >> rooms[i] >> L;
        forn (j, L) {
            ll x;
            cin >> x;
            bombs[i].push_back(x);
        } 
    }
    forn(r, N + 1) {
        if (r == 0) {
            // set everthing to 0 (which is the default)
        } else {
            forn(i, bombs[r - 1].size() + 1) {
                forn(j, T - rooms[r-1] + 1) {
                    if (i == 0) {
                        mbsmb[j] = mbbma[j];
                    } else {
                        mbsmb[j] = max(
                            mbsma[j],
                            (j - bombs[r-1][i-1] >= 0 ? mbsma[j - bombs[r-1][i-1]] + 1 : 0ll)  
                        );
                    }
                    mbbmb[j + rooms[r-1]] = max(mbbma[j + rooms[r-1]], mbsmb[j]);
                }
                forn(j, T - rooms[r-1] + 1) {
                    mbsma[j] = mbsmb[j];
                }
            }
            forn(j, T + 1) {
                mbbma[j] = mbbmb[j];
            }
        }
    }
    cout << mbbma[T] << endl;
}