#include <iostream>
#include <unordered_set>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;

ll X, Y, K;
ll suC[2000001] = {0}, difC[2000001] = {0};
unordered_set<ll> points;
ll ans = 0;

ll ep(pair<ll, ll> p) {
    return p.first * (Y+1) + p.second;
}

pair<ll, ll> dp(ll n) {
    pll p;
    p.first = n / (Y+1);
    p.second = n % (Y+1);
    return p;
}


bool hp(pair<ll, ll> p) {
    return points.find(ep(p)) != points.end();
}

bool gc(ll suP, ll difP) {
    if ((suP + difP) % 2 == 0) {
        pll center;
        center.first = (suP + difP) / 2;
        center.second = (suP - difP) / 2;
        if (hp(center)) {
            return true;
        }
    }
    return false;
}

ll cs(ll suP, ll difP) {
    ll kc = 0;
    ll c = 0;
    pll ps[2][2];
    if ((suP + difP) % 2 == 0) {
        ps[0][0].first = ((suP - 2) + difP) /2;
        ps[0][0].second = ((suP - 2) - difP) /2;
        ps[1][1].first = ((suP + 2) + difP) /2;
        ps[1][1].second = ((suP + 2) - difP) /2;
        ps[0][1].first = (suP + (difP - 2)) /2;
        ps[0][1].second = (suP - (difP - 2)) /2;
        ps[1][0].first = (suP + (difP + 2)) /2;
        ps[1][0].second = (suP - (difP + 2)) /2;
    } else {
        ps[0][0].first = ((suP - 1) + difP) /2;
        ps[0][0].second = ((suP - 1) - difP) /2;
        ps[1][1].first = ((suP + 1) + difP) /2;
        ps[1][1].second = ((suP + 1) - difP) /2;
        ps[0][1].first = (suP + (difP - 1)) /2;
        ps[0][1].second = (suP - (difP - 1)) /2;
        ps[1][0].first = (suP + (difP + 1)) /2;
        ps[1][0].second = (suP - (difP + 1)) /2;
    }
    while(
        ps[0][0].first >= 0 &&
        ps[0][0].second >= 0 &&
        ps[1][1].first <= X &&
        ps[1][1].second <= Y &&
        ps[0][1].first >= 0 &&
        ps[0][1].second <= Y &&
        ps[1][0].first <= X &&
        ps[1][0].second >= 0
    ) {
        forn (j, 2) {
            forn (k, 2) {
                kc += hp(ps[j][k]);
            }
        }
        if (kc == K) {
            c++;
        }
        ps[0][0].first--;
        ps[0][0].second--;
        ps[1][1].first++;
        ps[1][1].second++;
        ps[0][1].first--;
        ps[0][1].second++;
        ps[1][0].first++;
        ps[1][0].second--;
    }
    return c;
}

int main() {
    cin >> X >> Y >> K;
    points.reserve(K);
    if (K == 0) {
        for (ll size = 1; size <= min(X, Y); size++) {
            ans += (X - size + 1) * (Y - size + 1);
        }  
    } else if (K == 1) {
        ll x, y;
        cin >> x >> y;
        ans =  
        (
            (min(x, y) + 1) * 
            (min(X-x, Y-y) + 1)) + 
        (
            (min(x, Y-y) + 1) * 
            (min(X-x, y) + 1)
        ) - 
        (min(min(x, y), min(X - x, Y - y))) - 2;
    } else {
        forn (i, K) {
            pll p;
            cin >> p.first >> p.second;
            points.insert(ep(p));
            suC[p.first + p.second]++;
            difC[p.first - p.second + Y]++;
        }
        bool isOneLine = false;
        bool suOdif;
        ll c;
        forn(i, X+Y+1) {
            if (suC[i] == K) {
                isOneLine = true;
                suOdif = true;
                c = i;
            }
            if (difC[i] == K) {
                isOneLine = true;
                suOdif = false;
                c = i - Y;
            }
        }
        if (isOneLine) {
            if (suOdif) {
                px = 
            } else {

            }
        } else {
            pll a = dp(*points.begin());
            // move su first
            forn (suP, X + Y + 1) {
                ll difP = a.first - a.second;
                ll kc = suC[suP] + difC[difP - Y];
                if (gc(suP, difP)) {
                    kc--;
                }
                if (kc == K) {
                    ans += cs(suP, difP);
                }
            }
            forn (difP, X + Y + 1) {
                ll suP = a.first + a.second;
                ll kc = suC[suP] + difC[difP - Y];
                if (gc(suP, difP)) {
                    kc--;
                }
                if (kc == K) {
                    ans += cs(suP, difP);
                }
            }
        }
    }
    cout << ans << endl;
}