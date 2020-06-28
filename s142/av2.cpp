using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define forn(i, n) for(long long i = 0; i < n; i++)
typedef long long ll;

ll N;
ll ns[5000];
ll ans = 0;
unordered_set<ll> vp;
// sf: is continuous

ll ep(ll a, ll b) {
    return max(a, b) * N + min(a, b);
}

bool hp(ll a, ll b) {
    return vp.find(ep(a, b)) != vp.end();
}


void next(ll& x) {
    x++;
    if (x == N) {
        x = 0;
    }
}

ll norm(ll n) {
    if (n >= N) {
        n -= N;
    }
    if (n < 0) {
        n += N;
    }
    return n;
}

int main() {
    cin >> N;
    forn(i, N) {
        cin >> ns[i];
        ns[i] -= 1;
    }
    forn(a, N) {
        ll sum1 = ns[a];
        ll minN1 = ns[a];
        ll maxN1 = ns[a];
        for (ll d = 1; d < N; d++) {
            ll b = norm(a+d);
            if (!hp(a, b) && maxN1 - minN1 + 1 == d) {
                ans += 1;
                vp.insert(ep(a, b));
            }
            if (ns[b] < minN1) {
                minN1 = ns[b];
            }
            if (ns[b] > maxN1) {
                maxN1 = ns[b];
            }
            sum1 += ns[b];
        }
    }
    cout << ans << endl;
}
