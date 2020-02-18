#include <iostream>
#include <limits>
#include <climits>
#include <stdexcept>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;

ll ix, iy, xx, xy, yx, yy, xg, yg;

ll divi(ll a, ll b) {
    if (a==0) {
        return 0;
    }
    a--;
    b--;
    if (b) {
        return a/b;
    } else {
        return LONG_MAX;
    }
}
int main() {
    cin >> ix >> iy >> xx >> xy >> yx >> yy >> xg >> yg;
    // cout << ix << iy << xx << xy << yx << yy << xg << yg << endl;
    ll base = ix*xg + iy*yg;
    // cout << base << endl;
    ll maxCost = 0;

    // eat red first
    forn(i, min(divi(ix, xx), iy/xy)+1) {
        ll rx = ix - (xx-1)*i;
        if (rx < 0) throw runtime_error("");
        ll ry = iy - xy*i;
        if (ry < 0) throw runtime_error("");
        ll cost=xg*i + min(rx/yx, divi(ry,yy)) * yg;
        if (cost > maxCost) maxCost = cost;
    }
    forn(i, min(ix/yx, divi(iy,yy))+1) {
        ll rx = ix - (yx)*i;
        ll ry=iy - (yy-1)*i;
        if (ry < 0) throw runtime_error("");
        if (rx < 0) throw runtime_error("");
        // cout << "rx " << rx << " ry " << ry << endl;;
        ll cost = yg*i + min(divi(rx, xx), ry/xy) * xg;
        // cout << "cost " << cost << endl;
        if (cost > maxCost) maxCost = cost;
    }
    cout << maxCost + base << endl;
}