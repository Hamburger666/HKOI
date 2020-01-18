#include "stdc++.h"
#define forn(i, n) for (ll i = 0; i < n; i++)
#define form(i, n) for (ll i = 1; i <= n; i++)
using namespace std;
typedef long long ll;

ll circleIndex(ll n) {
    if (n >=0 && n < 3) {
        return n;
    }
    if (n == 3) {
        return 0;
    }
    if (n == -1) {
        return 2;
    }
    n = n % 3;
    if (n < 0) {
        n += 3;
    }
    return n;
}


ll rawTriangle[80][80];
ll tryTriangle[80][80];
ll N, A, B, K;
int main() {
    cin >> N >> A >> B >> K;
    forn(i, N) {
        forn(j, i + 1) {
            ll x;
            cin >> x;
            rawTriangle[i][j] = x;
        }
    }
    
    int minCost = INT_MAX;
    int minA, minB, minC;
    form(a, 128) {
        form(b, 128) {
            form(c, 128) {
                ll abc[3] = {a, b, c};
                ll start = 0;
                forn(layer, N) {
                    ll on = start;
                    forn(element, layer + 1) {
                        tryTriangle[layer][element] = abc[on];
                        on = circleIndex(on + 1);
                    }
                    start = circleIndex(start + 1);
                }

                ll cost = 0;
                forn(layer, N) {
                    forn(element, layer + 1) {
                        ll diff = tryTriangle[layer][element] - rawTriangle[layer][element];
                        if (diff > 0) {
                            cost += diff * A;
                        } else if (diff < 0) {
                            cost += -diff * B;
                        }
                    }
                }
                if (cost < minCost) {
                    minCost = cost;
                    minA = a;
                    minB = b;
                    minC = c;
                }
            }
        }
    }

    cout << minCost << endl;

    ll abc[3] = {minA, minB, minC};
    ll start = 0;
    forn(layer, N) {
        ll on = start;
        forn(element, layer + 1) {
            tryTriangle[layer][element] = abc[on];
            on = circleIndex(on + 1);
        }
        start = circleIndex(start + 1);
    }

    forn(layer, N) {
        forn(element, layer + 1) {
            cout << tryTriangle[layer][element] << " ";
        }
        cout << endl;
    }

}