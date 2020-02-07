#include <iostream>
#include <limits>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, M, pa, pb;
ll r, c, pg, ps;
ll vg, vs;
bool ox, px;
ll d, h;
ll j[2];
struct rc {
    ll r, c;
};
ll distance(rc a, rc b) {
    return (abs(a.r - b.r) + abs(a.c - b.c));
}

ll minCorner(rc cg, rc cs, ll pg, ll ps) {
    rc c00 = {0, 0};
    rc c01 = {0, c-1};
    rc c10 = {r-1, 0};
    rc c11 = {r-1, c-1};
    ll v00 = max(pg - distance(cg, c00), ps - distance(cs, c00));
    ll v01 = max(pg - distance(cg, c01), ps - distance(cs, c01));
    ll v10 = max(pg - distance(cg, c10), ps - distance(cs, c10));
    ll v11 = max(pg - distance(cg, c11), ps - distance(cs, c11));
    return max(0ll, min(v00, min(v01, min(v10, v11))));
}

string torcstring(rc c, bool ox) {
    if (ox) {
        return to_string(c.c + 1ll) + " " + to_string(c.r + 1ll) + " ";
    } else {
        return to_string(c.r + 1ll) + " " + to_string(c.c + 1ll) + " "; 
    }
}

rc correct(rc cc) {
    cc.r = max(0ll, min(r-1, cc.r));
    cc.c = max(0ll, min(c-1, cc.c));
    return cc;
}

bool outBound(rc rc) {
    return rc.r >=r || rc.r <0 || rc.c >= c || rc.c < 0;
}
int main() {
    cin >> N >> M >> pa >> pb;
    if (N > M) {
        ox = false;
        r = N;
        c = M;
    } else {
        ox = true;
        r = M;
        c = N;
    }

    if (pa > pb) {
        px = false;
        pg = pa;
        ps = pb;
    } else {
        px = true;
        pg = pb;
        ps = pa;
    }

    vg = max(0ll, pg - (c-1)/2);
    vs = max(0ll, ps - c/2);

    d = (r+1)/2;
    // cout << d << endl;
    if ((d + (vg - vs)) % 2 == 0) {
        d++;
    }
    d = min(r-1, d);
    // cout << d << endl;
    // cout << vg << " " << vs << endl;
    // cout << d << endl;
    h = (vg + vs - d + 1)/2;

    ll maxcost = 0; rc maxcg, maxcs;
    if (vg - vs < d && vs && vg  && h) {
        j[0] = vs - h;
        if (r%2==1) {
            j[1] = max(0ll, vs - h - 1);
        } else {
            j[1] = vs - h;
        }
        forn(u2, 2) {
            rc cg = {j[u2] + d, c/2};
            rc cs = {j[u2], (c-1)/2};
            if (outBound(cg) || outBound(cs)) {
                continue;
            }
            ll cost = min(h, minCorner(cg, cs, pg, ps));
            if (cost >= maxcost) {
                maxcost = cost;
                maxcg = cg;
                maxcs = cs;
            }
        }

        rc cg = {r/2, c/3};
        rc cs = {0, 0};
        ll cost = minCorner(cg, cs, pg, ps);
        if (cost >= maxcost) {
            maxcost = cost;
            maxcg = cg;
            maxcs = cs;
        }
    } else {
        // cout << "hi" << endl;
        maxcg.r = r/2; maxcg.c = c/2;
        maxcs.r = 0; maxcs.c = 0;
        maxcost = minCorner(maxcg, maxcs, pg, ps);
    } 

    cout << maxcost << endl;
    if (px) {
        cout << torcstring(maxcs, ox) << torcstring(maxcg, ox) << endl;
    } else {
        cout << torcstring(maxcg, ox) << torcstring(maxcs, ox) << endl;
    }
}