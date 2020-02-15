#include <iostream>
#include <unordered_set>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M, Q;
bool Ns[10000][100], cost[10000]; ll Qs[20000][20]; ll Qc[20000];
unordered_set<ll> movies[100][10000];
int main() {
    cin >> N >> M >> Q;
    forn(i, N) {
        cin >> cost[i];
    }
    forn(i, N) {
        forn(k, M) {
            cin >> Ns[i][k];
        }
    }
    forn(i, Q) {
        cin >> Qc[i];
        forn(j, Qc[i]) {
            cin >> Qs[i][j];
            Qs[i][j]--;
        }
    }

    forn(i, N) {
        forn(j, M) {
            movies[j][i] = Ns[i][j];
        }
    }

    forn(lid, Q) {
        ll c[100] = {0};
        forn(cid, N) {
            c[cid] = true;
        }
        forn(i, Qc[lid]) {
            mid = Qs[lid][i];
            
        }

    }

}