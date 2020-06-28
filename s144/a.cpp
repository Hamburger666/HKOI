#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll T, X, Y, Px, Qx, Py, Qy;
ll Tx[100000], Ty[100000];
ll maxC = 0, maxCT = 0;
int main() {
    cin >> T >> X >> Y >> Px >> Qx >> Py >> Qy;
    forn (i, X) {
        cin >> Tx[i];
    }
    forn (i, Y) {
        cin >> Ty[i];
    }
    for (ll t = T - Py - Qy; t >= Qx + Px; t--) {
        ll Xc = 0;
        forn(i, X) {
            Xc += (t - Qx - Px) / Tx[i];
        }
        ll Yc = 0;
        forn(i, Y) {
            Yc += (T - t - Py - Qy) / Ty[i];
        }
        if (Xc <= Yc) {
            if (Xc >= maxC) {
                maxC = Xc;
                maxCT = t;
            }
        }
    }
    cout << maxCT << endl;
    cout << maxC << endl;
}