#include <iostream>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

struct xy {
    ll x, y;
};
ll N, M, K;
xy a[2000];

bool within(xy a, xy b, ll c, ll ox, ll oy) {
    bool re = true;
    if (ox) {
        ll bs = a.x + c;
        re &= (a.x<=b.x && b.x <= bs);
    } else {
        ll bs = a.x - c;
        re &= (bs<=b.x && b.x <= a.x);
    }
    if (oy) {
        ll bs = a.y + c;
        re &= (a.y<=b.y && a.y<=bs);
    } else {
        ll bs = a.y - c;
        re &= (bs<=a.y && a.y<=b.y);
    }
    return re;
}
int main() {
    cin>>N>>M>>K;
    forn(i,K){
        cin >> a[i].x;
        a[i].x--;
        cin >> a[i].y;
        a[i].y--;
    }
    ll maxCost = 0;
    forn(ox, 2) forn(oy, 2) {
        forn(i, K) {
            ll cost = 0;
            forn(j, K) {
                if (within(a[i], a[j], M-1, ox, oy)) cost++;
            }
            if (cost > maxCost) maxCost = cost;
        }
    }
    cout << maxCost << endl;
}