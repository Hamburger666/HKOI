#include <iostream>
#include <unordered_set>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;

ll X, Y, K;
ll suC[2000001] = {0}, difC[2000001] = {0};
unordered_set<ll> suCV, difCV;
pll minSuP[2000001], maxSuP[2000001], minDifP[2000001], maxDifP[2000001];
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



int main() {
    cin >> X >> Y >> K;
    points.reserve(K);
    suCV.reserve(K);
    difCV.reserve(K);
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
        forn(i, K) {
            pll p;
            cin >> p.first >> p.second;
            points.insert(ep(p));
            ll su = p.first + p.second;
            ll dif = p.first - p.second;
            if (suC[su]) {
                if (p.first <= minSuP[su].first) {
                    minSuP[su] = p;
                }
                if (p.first >= maxSuP[su].first) {
                    maxSuP[su] = p;
                }
            } else {
                minSuP[su] = p;
                maxSuP[su] = p;
            }
            suC[su]++;
            suCV.insert(su);
            if (difC[dif + Y]) {
                if (p.first <= minDifP[dif + Y].first) {
                    minDifP[dif + Y] = p;
                }
                if (p.first >= maxDifP[dif + Y].first) {
                    maxDifP[dif + Y] = p;
                }
            } else {
                minDifP[dif + Y] = p;
                maxDifP[dif + Y] = p;
            }
            difC[dif + Y]++;
            difCV.insert(dif);
        }
        pll a = dp(*points.begin());
        bool isOneLine, suOdif;
        ll c;
        for (ll suP : suCV) {
            if (suC[suP] == K) {
                isOneLine = true;
                suOdif = true;
                c = suP;
            }
        }
        for (ll difP : difCV) {
            if (difC[difP] == K) {
                isOneLine = true;
                suOdif = false;
                c = difP - Y;
            }
        }
        if (isOneLine) {
            if (suOdif) {
                pll minP = minSuP[c];
                pll maxP = maxSuP[c];
                ans = (min(minP.first, Y - minP.second) + 1) * (min(X - maxP.first, maxP.second) + 1);
            } else {
                pll minP = minDifP[c + Y];
                pll maxP = maxDifP[c + Y];
                ans = (min(minP.first, minP.second) + 1) * (min(X - maxP.first, Y - maxP.second) + 1);
            }
        } else {
            // move su first
            for (ll suP : suCV) {
                ll difP = a.first - a.second;
                ll kc = suC[suP] + difC[difP - Y];
                if ((suP + difP) % 2 == 0) {
                    pll center;
                    center.first = (suP + difP) / 2;
                    center.second = (suP - difP) / 2;
                    if (hp(center)) {
                        kc--;
                    }
                }
                if (kc == K) {
                    pll minSuPp, maxSuPp, minDifPp, maxDifPp;
                    minSuPp = minSuP[suP];
                    maxSuPp = maxSuP[suP];
                    minDifPp = minDifP[difP + Y];
                    maxDifPp = maxDifP[difP + Y];
                    ans += min(
                        min(
                            min(minSuPp.first, Y - minSuPp.second), 
                            min(X - maxSuPp.first, maxSuPp.second)
                        ), 
                        min(
                            min(minDifPp.first, minDifPp.second), 
                            min(X - maxDifPp.first, Y - maxDifPp.second)
                        )
                    ) + 1;
                }
            }
            // them move dif
            for (ll difP : difCV) {
                ll suP = a.first + a.second;
                ll kc = suC[suP] + difC[difP - Y];
                if ((suP + difP) % 2 == 0) {
                    pll center;
                    center.first = (suP + difP) / 2;
                    center.second = (suP - difP) / 2;
                    if (hp(center)) {
                        kc--;
                    }
                }
                if (kc == K) {
                    pll minSuPp, maxSuPp, minDifPp, maxDifPp;
                    minSuPp = minSuP[suP];
                    maxSuPp = maxSuP[suP];
                    minDifPp = minDifP[difP + Y];
                    maxDifPp = maxDifP[difP + Y];
                    ans += min(
                        min(
                            min(minSuPp.first, Y - minSuPp.second), 
                            min(X - maxSuPp.first, maxSuPp.second)
                        ), 
                        min(
                            min(minDifPp.first, minDifPp.second), 
                            min(X - maxDifPp.first, Y - maxDifPp.second)
                        )
                    ) + 1;
                }
            }
        }
    }
    cout << ans << endl;
}