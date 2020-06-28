#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll T, X, Y, Px, Qx, Py, Qy;
ll Tx[100000], Ty[100000];
ll maxC = 0, maxCT = 0;

ll biS(ll left, ll right) {
    if (left + 1 == right) {
        return left;
    } else {
        ll mid = (left + right) / 2;
        ll Xc = 0;
        forn(i, X) {
            Xc += (mid - Qx - Px) / Tx[i];
        }
        ll Yc = 0;
        forn(i, Y) {
            Yc += (T - mid - Py - Qy) / Ty[i];
        }
        if (Xc <= Yc) {
            return biS(mid, right);
        } else {
            return biS(left, mid);
        }
    }
}
int main() {
    cin >> T >> X >> Y >> Px >> Qx >> Py >> Qy;
    forn (i, X) {
        cin >> Tx[i];
    }
    forn (i, Y) {
        cin >> Ty[i];
    }
    ll s = biS(Px + Qx, T - Py - Qy + 1);
    ll minD = T;
    forn(i, X) {
        if ((s - Px - Qx) % Tx[i] < minD) {
            minD = (s - Px - Qx) % Tx[i];
        }
    }
    ll t = s - minD;
    ll Xc = 0;
        forn(i, X) {
            Xc += (t - Qx - Px) / Tx[i];
        }
    ll Yc = 0;
    forn(i, Y) {
        Yc += (T - t - Py - Qy) / Ty[i];
    }
    cout << s << endl;
    cout << Xc << endl;
}