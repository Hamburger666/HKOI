#include <iostream>
#include <algorithm>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

struct xyz {
    ll x, y, z;
};

ll Xr, Yr, Zr, X, Y, Z, K;
xyz moves[128000]; ll ms = 0;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first > b.first;
}
int main() {
    cin >> Xr >> Yr >> Zr >> K;
    
    pair<ll, ll> t[3] = {make_pair(Xr, 0), make_pair(Yr, 1), make_pair(Zr, 2)};
    sort(t, t+3, comp);
    X = t[0].first;
    Y = t[1].first;
    Z = t[2].first;
    
    while(X != 0 && X != 1) {
        int c = ((X > 0) ? -1 : 1);
        X += 2*c;
        if (abs(Y) > abs(Z)) {
            int c = ((Y>0) ? -1 : 1);
            Y += 1*c;
        } else {
            int c = ((Z > 0) ? -1 : 1);
            Z += 1*c;
        }
        xyz n = {X, Y, Z};
        moves[ms++] = n;
    }

    while(abs(Z) > 1) {
        int cy = ((Y > 0) ? -1 : 1);
        int cz = ((Z > 0) ? -1 : 1);
        Y += 2*cy;
        Z += 1*cz;
        xyz n1 = {X, Y, Z};
        cy = ((Y > 0) ? -1 : 1);
        cz = ((Z > 0) ? -1 : 1);
        Y += 1*cy;
        Z += 2*cz;
        xyz n2 = {X, Y, Z};
        moves[ms++] = n1;
        moves[ms++] = n2;  
    }
    while(Y != 0 && Y != 1 && (abs(X) + abs(Y)) > abs(Z) / 2) {
        int c = ((Y > 0) ? -1 : 1);
        Y += 2*c;
        c = ((Z > 0) ? -1 : 1);
        Z += 1*c;
        xyz n = {X, Y, Z};
        moves[ms++] = n;
    }
    while(Z != 0 && Z != 1) {
        int c = ((Z > 0) ? -1 : 1);
        Z += 2*c;
        if (X != 0) {
            int c = ((X > 0) ? -1 : 1);
            X += 1*c;
        } else {
            int c = ((Y > 0) ? -1 : 1);
            Y += 1*c;
        }
        xyz n = {X, Y, Z};
        moves[ms++] = n;
    }

    while (X != 0) {
        int c = ((X > 0) ? -1 : 1);
        X += 1*c;
        c = ((Z > 0) ? -1 : 1);
        Z += 2*c;
        xyz n = {X, Y, Z};
        moves[ms++] = n;
    }
    while (Y != 0) {
        int c = ((Y > 0) ? -1 : 1);
        Y += 1*c;
        c = ((Z > 0) ? -1 : 1);
        Z += 2 * c;
        xyz n = {X, Y, Z};
        moves[ms++] = n;
    }

    while(abs(Z) > 2) {
        int c = ((Z > 0) ? -1 : 1);
        Z += 2*c;
        Y += 1;
        xyz n = {X, Y, Z};
        moves[ms++] = n;
        Z += 2*c;
        Y -= 1;
        xyz n2 = {X, Y, Z};
        moves[ms++] = n2;
    }

    while(Z != 0 && Z != 1) {
        int c = ((Z > 0) ? -1 : 1);
        Z += 1*c;
        Y += 2;
        xyz n = {X, Y, Z};
        moves[ms++] = n;
        Z += 1*c;
        Y -= 2;
        xyz n2 = {X, Y, Z};
        moves[ms++] = n2;
    }

    if (Z == 1) {
        xyz n1 = {0, 2, 0};
        xyz n2 = {0, 1, 2};
        xyz n3 = {0, 0, 0};
        moves[ms++] = n1;
        moves[ms++] = n2;
        moves[ms++] = n3;
    }

    cout << ms << endl;
    cout << Xr << " " << Yr << " " << Zr << endl;
    forn(i, ms) {
        ll s[3];
        s[t[0].second] = moves[i].x;
        s[t[1].second] = moves[i].y;
        s[t[2].second] = moves[i].z;
        cout << s[0] << " " << s[1] << " " << s[2] << endl;
    }
    
}
