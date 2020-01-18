#include "stdc++.h"
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
using namespace std;
typedef long long ll;

ll N, A, B, K;
ll rawTriangle[80][80];
ll calcedTriangle[80][80];

int circleIndex(int i) {
    if (i == -1) {
        return 2;
    } else if (i == 3) {
        return 0;
    } else {
        return i;
    }
}
int main() {
    cin >> N >> A >> B >> K;
    if (K != 1) {
        return 0;
    }

    forn(layer, N) {
        forn(element, layer + 1) {
            cin >> rawTriangle[layer][element];
        }
    }

    ll minCost = INT_MAX, minA, minB, minC;
    form(a, 128) {
        form(b, 128) {
            form(c, 128) {
                ll abc[3] = {a, b, c};
                ll startOn = 0;
                forn(layer, N) {
                    ll letter = startOn;
                    forn(element, layer + 1) {
                        letter = circleIndex(letter + 1);
                        calcedTriangle[layer][element] = abc[letter];
                    }
                    startOn = circleIndex(startOn + 1);
                }

                ll cost = 0;
                forn(layer, N) {
                    forn(element, layer + 1) {
                        ll diff = calcedTriangle[layer][element] - rawTriangle[layer][element];

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


    ll abc[3] = {minA, minB, minC};
    ll startOn = 0;
    forn(layer, N) {
        ll letter = startOn;
        forn(element, layer + 1) {
            letter = circleIndex(letter + 1);
            calcedTriangle[layer][element] = abc[letter];
        }
        startOn = circleIndex(startOn + 1);
    }

    cout << minCost << endl;
    forn(layer, N) {
        forn(element, layer + 1) {
            cout << calcedTriangle[layer][element] << " ";
        }
        cout << endl;
    }

}