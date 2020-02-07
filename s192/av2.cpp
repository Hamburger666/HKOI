#include <iostream>
#include <string>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
using namespace std;
typedef long long ll;

ll R, C, pa, pb;
ll g, s, pg, ps;
bool ox, px;

struct rc {
    ll r, c;
};

string tocsg(rc c, bool x) {
    if (x) {
        return to_string(c.c + 1ll) + " " + to_string(c.r + 1ll) + " ";
    } else {
        return to_string(c.r + 1ll) + " " + to_string(c.c + 1ll) + " ";
    }
}

int main() {
    cin >> R >> C >> pa >> pb;

    if (R > C) {
        px = false;
        g = R;
        s = C;
    } else {
        ox = true;
        g = C;
        s = R;
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
    
    if (s / 2 != 0 || g / 2 != 0) {
        throw runtime_error("");
    }

    rc cg = {g/2, s/2};
    ll maxv = 0; rc maxcs; ll maxj;
    forn(u101, 2) {

        ll vg = pg - cg.c;
        ll vs = ps - max(0ll, (s - u101) / 2);
        ll j;
        if ((vg - vs) < (cg.r)) {
            j = ((vg - vs) + (cg.r)) / 2 - (vg - vs);
        } else {
            j = 0;
        }
        ll k[2];
        k[0] = 0;
        if (((vg - vs) + (cg.r)) % 2 == 0) {
            k[1] = -1;
        } else {
            k[1] = 1;
        }
        forn(u201, 2) {
            forn(u301, 2) {
                rc cs = {k[u301], (s - u101)/2};
                j = j - u201;
                if (cs.r + j < 0) {
                    continue;
                }
                ll v00 = max(ps - (cs.r + j) - (cs.c), pg - (cg.r + j) - (cg.c));
                ll v01 = max(ps - (cs.r + j) - (s - 1 - cs.c), pg - (cg.r + j) - (s - 1 - cg.c));
                ll v10 = pg - (g - 1 - (cg.r + j)) - (cg.c);
                ll v11 = pg - (g - 1 - (cg.r + j)) - (s - 1 - cg.c);
                ll minv = max(0ll, min(v00, min(v01, min(v10, v11))));
                if (minv >= maxv) {
                    maxv = minv;
                    maxcs = cs;
                    maxj = j;
                }
            }
        }
    }

    cout << maxv << endl;
    cg.r += maxj;
    maxcs.r += maxj;
    if (px) {
        cout << tocsg(maxcs, ox) << tocsg(cg, ox) << endl;
    } else {
        cout << tocsg(cg, ox) << tocsg(maxcs, ox) << endl;
    }

}