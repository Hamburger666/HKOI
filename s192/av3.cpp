#include <iostream>
#define forn(i, a, b) for (long long i = a; i < b; i++)
typedef long long ll;
using namespace std;

int N, M, pa, pb;
int r, c, pg, ps;
bool ox, px;

struct rc {
    long long r, c;
};


ll midv(rc cg, rc cs, ll pg, ll ps, ll i) {

    // if (cg.c < 0 || cs.c < 0) {
    //     cout << "negative" << endl;
    // }

    // if (pg > 10 || ps > 10) {
    //     cout << "-----asdgasdg asdrqwerh -----" << endl;
    //     cout << pg << " " << ps << endl;
    //     cout << "--------" << endl;
    // }
    ll vg, vs;
    if (!i) {
        vg = pg - cg.c;
        vs = ps - cs.c;
    } else {
        vg = pg - (c - 1 - cg.c);       
        vs = ps - (c - 1 - cs.c);
    }
    // printf("vg %lld\n", vg);
    // cout << (cg.r >= cs.r? "true" : "false") << endl;

    if (abs(vg - vs) >= (cg.r - cs.r)) {
        return LONG_MAX;
    }

    // if (vg > 10 || vs > 10) {
    //     cout << "---asjdgalksdjgakl;sjdgl;kajsdgkl;ajsdf=-----" << endl;
    //     cout << vg << " " << vs << endl;
    //     cout << " ---asd-g-----------" << endl;
    // }

    // if (max(vg, vs) > 10) {
    //     cout <<"alsjdg;lkajsd;lgkjals;dkgjasdg" << endl;
    //     cout << vg << " " << vs << endl;
    //     cout << "---------" << endl;
    // }
    return max(vg, vs) - (abs(vg - vs) + (cg.r - cs.r)) / 2; 
} 

string tocsg(rc c, bool x) {
    if (x) {
        return to_string(c.c + 1ll) + " " + to_string(c.r + 1ll) + " ";
    } else {
        return to_string(c.r + 1ll) + " " + to_string(c.c + 1ll) + " ";
    }
}


bool inBound(rc coord) {
    return (coord.r >= 0 && coord.r < r && coord.c >= 0 && coord.c < c);
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
        // cout << "incorrect" << endl;
        px = false;
        pg = pa;
        ps = pb;
    } else {
        px = true;
        pg = pb;
        ps = pa;
    }

    rc center = {r/2, c/2};
    ll vg = pg - center.c;
    ll vs = ps - center.c;
    ll jc;
    if ((vg - vs) < (center.r)) {
        jc = vs - (vg - ((vg - vs) + (center.r)) / 2);
    } else {
        jc = 0;
    }
    // cout << jc << endl;
    // cout << r << " " << c <<endl;
    ll maxv = 0; rc maxcg, maxcs; ll maxj;
    forn(j01, -2, 3) {
        forn(gr01, -2, 3) {
            forn(gc01, -2, 3) {
                forn(sr01, -2, 3) {
                    forn(sc01, -2, 3) {
                        ll j = jc + j01;
                        if (j < 0) {
                            continue;
                        }
                        rc cg = {center.r + gr01 + j, center.c + gc01};
                        rc cs = {0 + sr01 + j, center.c + sc01};
                        // cout << cg.r << " " << cg.c << " " << cs.r << " " << cs.c << " " << endl;
                        // cout << inBound(cg) << " " << inBound(cs) << endl;
                        if (!inBound(cg) || !inBound(cs)) {
                            continue;
                        }
                        ll v00 = max(ps - (cs.r + j) - (cs.c), pg - (cg.r + j) - (cg.c));
                        ll v01 = max(ps - (cs.r + j) - (c - 1 - cs.c), pg - (cg.r + j) - (c - 1 - cg.c));
                        ll v10 = pg - (r - 1 - (cg.r + j)) - (cg.c);
                        ll v11 = pg - (r - 1 - (cg.r + j)) - (c - 1 - cg.c);
                        ll v02 = midv(cg, cs, pg, ps, 0);
                        // cout << v02 << endl;
                        ll v12 = midv(cg, cs, pg, ps, 1);
                        ll minv = max(0ll, min(v00, min(v01, min(v10, min(v11, min(v02, v12))))));
                        if (minv >= maxv) {
                            // cout << "hi" << endl;
                            maxv = minv;
                            // cout << tocsg(cg, 0) << tocsg(cs, 0) << endl;
                            // cout << "asdgggff " << v02 << " " << v12 << endl;
                            maxcg = cg;
                            maxcs = cs;
                        }
                    }
                }
            }
        }
    }

    cout << maxv << endl;
    // cout << px << endl;
    if (px) {
        cout << tocsg(maxcs, ox) << tocsg(maxcg, ox) << endl;
    } else {
        cout << tocsg(maxcg, ox) << tocsg(maxcs, ox) << endl;
    }


}
