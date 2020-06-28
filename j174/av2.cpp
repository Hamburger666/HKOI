#include <iostream>
#include <unordered_set>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;
// need to restart because it gets messy 

// sf: standard to diagonal
pair<ll, ll> std(pair<ll, ll> sp) {
    pair<ll, ll> dp;
    dp.first = sp.first + sp.second;
    dp.second = sp.first - sp.second + Y;
    return dp;
}

// sf: diagonal to standard
pair<ll, ll> dts(pair<ll, ll> dp) {
    pair<ll, ll> sp;
    ll su = dp.first;
    ll dif = dp.second - Y;
    sp.first = (su + dif) / 2;
    sp.second = (su - dif) / 2;
    return sp;
}

// sf: can diagnao to standard
bool cdts(pair<ll, ll> dp) {
    return (dp.first + dp.second) % 2 == 0;
}

// sf: encode point
ll ep(pair<ll, ll> sp) {
    return sp.first * (Y+1) + sp.second;
}

// sf: decode point
pair<ll, ll> dp(ll n) {
    pair<ll, ll> re;
    re.first = n / (Y+1);
    re.second = n % (Y+1);
    return re;
}

pair<ll, ll> gSuP(ll su) {
    pair<ll, ll> suP;
    suP.first = su;
    suP.second = 0;
}

pair<ll, ll> gDifP(ll dif) {
    dif = dif - Y;
    pair<ll, ll> difP;
    if (dif < 0) {
        difP.first = 0;
        difP.second = -dif;
    } else {
        difP.first = dif;
        difP.second = 0;
    }
}

bool hp(pair<ll, ll> p) {
    return points.find(ep(p)) != points.end();
}

pair<pair<ll, ll>, pair<ll, ll> > gMinMaxSuP(ll su) {
    pair<ll, ll> p = gSuP(su);
    pair<ll, ll> minSuP;
    minSuP.first = X;
    pair<ll, ll> maxSuP;
    maxSuP.first = 0;
    while(p.first >= 0 && p.second <= Y) {
        if (hp(p)) {
            if (p.first <= minSuP.first) {
                minSuP.first = p.first;
                minSuP.second = p.second;
            }
            if (p.first >= maxSuP.first) {
                maxSuP.first = p.first;
                maxSuP.second = p.second;
            }
        }
        p.first--;
        p.second++;
    }
    pair<pair<ll, ll>, pair<ll, ll> > re;
    re.first = minSuP;
    re.second = maxSuP;
    return re;
}

pair<pair<ll, ll>, pair<ll, ll> > getMinMaxDifP(ll dif) {
    dif = dif - Y;
    pair<ll, ll> p = gDifP(dif);
    pair<ll, ll> minDifP;
    minDifP.first = X;
    pair<ll, ll> maxDifP;
    maxDifP.first = 0;
    while(p.first <= X && p.second <= Y) {
        if (hp(p)) {
            if (p.first <= minDifP.first) {
                minDifP.first = p.first;
                minDifP.second = p.second;
            }
            if (p.first >= maxDifP.first) {
                maxDifP.first = p.first;
                maxDifP.second = p.second;
            }
        }
        p.first++;
        p.second++;
    }
}

ll X, Y, K;
unordered_set<ll> points;
ll su[2000001] = {0};
ll dif[2000001] = {0};
ll ans = 0;
int main() {
    cin >> X >> Y >> K;
    if (K == 1){

    } else {
         forn(i, K-1) {
            pair<ll, ll> sp;
            cin >> sp.first >> sp.second;
            pair<ll, ll> dp = std(sp);
            su[dp.first]++;
            dif[dp.second]++;
            points.insert(ep(sp));
        }
        pair<ll, ll> a;
        cin >> a.first >> a.second;
        points.insert(ep(a));
        pair<ll, ll> b = std(a);
        su[b.first]++;
        dif[b.second]++;

        bool isOneLine = false;
        forn (i, X+Y+1) {
            isOneLine |= su[i] == K || dif[i] == K;
        }
        if (isOneLine) {
            bool suOdif = true;
            ll c;
            forn (i, X+Y+1) {
                if (su[i] == K) {
                    suOdif = true;
                    c = i;
                    break;
                } else if (dif[i] == K) {
                    suOdif = false;
                    c = i;
                    break;
                }
            }
            if (suOdif) {
                pair<pair<ll, ll>, pair<ll, ll> > t = getMinMaxDifP(c);
                pair<ll, ll> minP = t.first;
                pair<ll, ll> maxP = t.second;
                ans = (min(minP.first, Y - minP.second) + 1) * (min(X - maxP.first, maxP.second) + 1);
            } else {
                pair<ll, ll> p;
 
                if (c < 0) {
                    p.second = -c;
                    p.first = 0;
                } else {
                    p.first = c;
                    p.second = 0;
                }
                // you might notice the way i coded it is quite lazy. But it doesn't hurt that much and it's more robust than the other way (note the first and last occurance).
                pair<pair<ll, ll>, pair<ll, ll> > t = getMinMaxDifP(c);
                pair<ll, ll> minP = t.first;
                pair<ll, ll> maxP = t.second;
                ans = (min(minP.first, minP.second) + 1) * (min(X - maxP.first, Y - maxP.second) + 1);
            }
        } else {
            // move su first
            forn(i, X + Y + 1) {
                ll kc = su[i] + dif[b.second];
                pair<ll, ll> dp;
                dp.first = i;
                dp.second = b.second;
                if (cdts(dp) && points.find(ep(dts(dp))) != points.end()) {
                    kc--;
                }
                if (kc == K) {
                    pair<pair<ll, ll>, pair<ll, ll> > tSu = gMinMaxSuP(i);
                    pair<pair<ll, ll>, pair<ll, ll> > tDif = getMinMaxDifP(b.second);
                    pair<ll, ll> suMinP, suMaxP, difMinP, difMaxP;
                    suMinP = tSu.first;
                    suMaxP = tSu.second;
                    difMinP = tDif.first;
                    difMaxP = tDif.second;

                }
            }
            // move dif then
            forn(i, X + Y + 1) {

            }
        }
    }
}