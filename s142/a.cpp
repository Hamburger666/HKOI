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
bool ic(vector<ll> numbers) {

}

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
        for (ll d = 1; d < N; d++) {
            ll b = norm(a + d);
            vector<ll> nss1;
            nss1.reserve(N);
            for (ll i = a; i != b; next(i)) {
                nss1.push_back(ns[i]);
            }
            sort(nss1.begin(), nss1.end());
            ll minN1 = *nss1.begin();
            ll maxN1 = *(nss1.end()-1);
            if (!hp(a, b) && maxN1 - minN1 + 1 == nss1.size()) {
                ans += 1;
                vp.insert(ep(a, b));
            }
        }
    }
    cout << ans << endl;
}
