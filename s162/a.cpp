using namespace std;
#include <iostream>
#include <stdexcept>
typedef long long ll;

ll colorDif (ll a, ll b) {
    ll d = a-b;
    if (d < 0) {
        d += 4;
    }
    return d;
}

ll countColor (ll color, ll minX, ll minY, ll maxX, ll maxY) {
    ll difX, difY;
    difX = maxX - minX + 1;
    difY = maxY - minY + 1;
    ll lowerStart = colorDif(color, ((minX + minY) % 4));
    ll lowerTriangle = (lowerStart + (min(difX, difY) - 1 - lowerStart) / 4 * 4 + lowerStart) * ((min(difX, difY) - 1 - lowerStart) / 4 * 4 + 1) / 2;
    ll upperEnd = colorDif((maxX, maxY) % 4, color);
    ll upperTriangle = (upperEnd + (min(difX, difY) - 1 - upperEnd) / 4 * 4 + upperEnd)
}