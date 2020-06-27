#include <iostream>
#include <unordered_set>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;


ll X, Y, K;
ll ans;
unordered_set<ll> points;

ll ep(ll x, ll y) {
    return x * (Y+1) + y;
} 

pll dp(ll n) {
    pll p;
    p.first = n / (Y+1);
    p.second = n % (Y+1);
    return p;
}

bool hp(ll x, ll y) {
    return points.find(ep(x, y)) != points.end();
}

ll cs(double cx, double cy) {
    ll ans = 0;
    if ((ll)(cx) == cx){
        ll kc = 0;
        if (hp((ll)cx, (ll)cy)) {
            kc++;
        }
        for (ll r = 1; r <= min(min(cx, X - cx), min(cy, Y - cy)); r++) {
            ll x = (ll)(cx - r);
            ll y = (ll)(cy - r);
            ll xb = (ll)(cx + r);
            ll yb = (ll)(cy + r);
            kc += hp(x, y);
            kc += hp(x, yb);
            kc += hp(xb, y);
            kc += hp(xb, yb);
            if (kc == K) {
                ans++;
            }            
        }
    } else {
        ll kc = 0;
        for (double r = 0.5; r <= min(min(cx, X - cx), min(cy, Y - cy)); r += 1) {
            ll x = (ll)(cx - r);
            ll y = (ll)(cy - r);
            ll xb = (ll)(cx + r);
            ll yb = (ll)(cy + r);
            kc += hp(x, y);
            kc += hp(x, yb);
            kc += hp(xb, y);
            kc += hp(xb, yb);
            if (kc == K) {
                ans++;
            }            
        }
    }
    return ans;
}

int main() {
    cin >> X >> Y >> K;
    forn(i, K) {
        ll x, y;
        cin >> x >> y;
        points.insert(ep(x, y));
    }

    for (ll cx = 1; cx <= X - 1; cx++) {
        for (ll cy = 1; cy <= Y - 1; cy++) {
            ans += cs(cx, cy);
        }
    }
    for (double cx = 0.5; cx <= X - 0.5; cx += 1) {
        for (double cy = 0.5; cy <= Y - 0.5; cy += 1) {
            ans += cs(cx, cy);
        }
    }
    cout << ans;
}