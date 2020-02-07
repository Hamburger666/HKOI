#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

struct rc {
    ll r, c;
};
ll R, C, pa, pb;
bool x;
bool y;
ll pg, ps;
ll g, s;
ll vg, vs;

string tocs(rc c) {
    return to_string(c.r + 1) + " " + to_string(c.c + 1) + " ";
}
int main() {
    cin >> R >> C >> pa >> pb;
    if (pa > pb) {
        x = false;
        pg = pa;
        ps = pb;
    } else {
        x = true;
        pg = pb;
        ps = pa;
    }

    if (R > C) {
        y = false;
        g = R;
        s = C;
    } else {
        y = true;
        g = C;
        s = R;
    }

    
    rc center;
    center.r = ((g - 1)/ 2);
    center.c = ((s - 1)/ 2);
    vg = pg - (g - 1 - center.r) - (s - 1 - center.c);
    vs = ps - (s - 1 - center.c);

    if (vs >= vg) {
        rc cg;
        cg.r = max(0ll, center.r - (vs - vg + 1) / 2);
        cg.c = center.c;
        rc cs;
        cs.r = min(g-1, g - (vs - vg + 1) / 2);
        ll s;
        cs.c = center.c;
        ll v001 = pg - (cg.r) - (cg.c);
        ll v011 = pg - (cg.r) - (s - 1 - cg.c);
        ll v101 = ps - (g - 1 - cs.r) - (cs.c);
        ll v111 = ps - (g - 1 - cs.r) - (s - 1 - cs.c);
        cout << v001 << " " << v011 << " " << v101 << " " << v111 << endl;
        ll s1 = max(0ll, min(v001, min(v011, min(v101, v111))));

        cs.c = g/2;
        ll v002 = pg - (cg.r) - (cg.c);
        ll v012 = pg - (cg.r) - (s - 1 - cg.c);
        ll v102 = max(pg - ((g - 1 - cg.r) - (cg.c)), ps - (g - 1 - cs.r) - (cs.c));
        ll v112 = ps - (g - 1 - cs.r) - (s - 1 - cs.c);
        ll s2 = max(0ll, min(v002, min(v012, min(v102, v112))));
        cout << v002 << " " << v012 << " " << v102 << " " << v112 << endl;

        if (s2 > s1) {
            s1 = s2;
        } else {
            cs.c = center.c;
        }

        cout << s1 << endl;
        // cout << cg.c << endl;
        if (y) {
            ll t = cg.r;
            cg.r = cg.c;
            cg.c = t;
               t = cs.r;
            cs.r = cs.c;
            cs.c = t;
        }


        if (x) {
            cout << tocs(cs) << tocs(cg) << endl;
        } else {
            cout << tocs(cg) << tocs(cs) << endl;
        }

    } else {
        cout << max(0ll, vg) << endl;
        rc cg;
        cg.r = center.r;
        cg.c = center.c;
        rc cs;
        cs.r = 0;
        cs.c = 0;
        if (y) {
            ll t = cg.r;
            cg.r = cg.c;
            cg.c = t;
        }
        if (x) {
            cout << tocs(cs) << tocs(cg) << endl;
        } else {
            cout << tocs(cg) << tocs(cs) << endl;
        }
    }
}