#include <iostream>
#include <unordered_set>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;

ll X, Y, K;
unordered_set<ll> points;
ll suC[2000001], difC[2000001];
ll ans = 0;

ll ep(ll x, ll y) {
    return x * (Y+1) + y;
}

pair<ll, ll> dp(ll n) {
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
        points.reserve(K);
        forn (i, K) {
            ll x, y;
            cin >> x >> y;
            points.insert(ep(x, y));
            suC[x+y]++;
            difC[x-y+Y]++;
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
                ll px, py;
                pll minP, maxP;
                minP.first = X;
                maxP.first = 0;
                if (c <= Y) {
                    px = 0;
                    py = c;
                } else {
                    px = c - Y;
                    py = Y;
                }
                while (px <= X && py >= 0) {
                    if (hp(px, py)) {
                        if (px <= minP.first) {
                            minP.first = px;
                            minP.second = py;
                        }
                        if (px >= maxP.first) {
                            maxP.first = px;
                            maxP.second = py;
                        }
                    }
                    px++;
                    py--;
                }
                ans = (min(minP.first, Y - minP.second) + 1) * (min(X - maxP.first, maxP.second) + 1);
            } else {
                ll px, py;
                pll minP, maxP;
                minP.first = X;
                maxP.first = 0;
                if (c > 0) {
                    px = c;
                    py = 0;
                } else {
                    px = 0;
                    py = -c;
                }
                while (px <= X && py <= Y) {
                    if (hp(px, py)) {
                        if (px <= minP.first) {
                            minP.first = px;
                            minP.second = py;
                        }
                        if (px >= maxP.first) {
                            maxP.first = px;
                            maxP.second = py;
                        }
                    }
                    px++;
                    py++;
                }
                ans = (min(minP.first, minP.second) + 1) * (min(X - maxP.first, Y - maxP.second) + 1);
            }
        } else {
            pll a = dp(*points.begin());
            // move at ++, ++ first 
            double px, py;
            if (a.first - a.second > 0) {
                px = a.first - a.second + 0.5;
                py = 0.5;
            } else {
                px = 0.5;
                py = a.second - a.first + 0.5;
            }
            while (px <= X - 0.5 && py <= Y - 0.5) {
                ll kc = suC[(ll)(px+py)] + difC[(ll)(px-py)+Y];
                if ((ll)px == px && (ll)py == py && hp((ll)px, (ll)py)) {
                    kc--;
                }
                if (kc == K) {
                    ans += cs(px, py);
                }
                px += 0.5;
                py += 0.5;
            }

            // move at ++, -- then
            
            if (a.first + a.second <= Y) {
                px = 0.5;
                py = a.first + a.second - 0.5;
            } else {
                px = a.first + a.second + 0.5 - Y;
                py = Y - 0.5;
            }
            while (px <= X - 0.5 && py >= 0.5) {
                ll kc = suC[(ll)(px+py)] + difC[(ll)(px-py)+Y];
                if ((ll)px == px && (ll)py == py && hp((ll)px, (ll)py)) {
                    kc--;
                }
                if (kc == K) {
                    ans += cs(px, py);
                }
                px += 0.5;
                py -= 0.5;
            }
            ans -= cs(a.first, a.second);
        }
    }
    cout << ans << endl;
}