#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, T;
ll rooms[50];
vector<ll> bombs[50];

ll mbb(ll j, ll r);

ll mbs(ll j, ll r, ll i) {
    ll re;
    if (j < 0) {
        re = -1;
    } else if (i == 0) {
        re = mbb(j, r - 1);
    } else {
        re = max(mbs(j, r, i-1), mbs(j - bombs[r-1][i-1], r, i - 1) + 1);
    }
    return re;
}

ll mbb(ll j, ll r) {
    ll re;
    if (r == 0) {
        re = 0;
    } else {
        re = max(mbb(j, r-1), mbs(j - rooms[r-1], r, bombs[r-1].size()));
    }
    return re;
}

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
    cout << mbb(T, N) << endl;
}