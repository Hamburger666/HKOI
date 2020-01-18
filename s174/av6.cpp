#include <iostream>
#include "stdc++.h"
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll

ll N, A, B, K;
ll tri[80][80];
bool tryTri[80][80] = {0};
vector<ll> subTri[80][80];
vector<ll> subTriCost[513][3];
vector<ll> subTriMeta;
ll subTriC = 0;
vector<ll> dpCost[1537][3]; // dpCost[sum][abc][ttt] = minCost
vector<ll> dpNum[1537][3][3]; // dpNum[sum][abc(which is added)][abc(which is in question)][ttt] = Num;
vector<ll> dpNeg[1537][3];


ll getNext(ll p) {
    p++;
    if (p == 3) p = 0;
    return p;
}
int main() {
    cin >> N >> A >> B >> K;
    forn(i, N) {
        forn(k, i + 1) {
            cin >> tri[i][k];
        }
    }

    forn(i, N) {
        forn(k, i + 1) {
            if (tryTri[i][k]) {
                continue;
            }
            ll oi = i, ok = k, layerCount = 0;
            forn(a, 80) forn(b, 80) subTri[a][b].push_back(0);
            subTriC++;
            for (ll ci = oi; ci < N; ci += K) {
                ll elementCount = 0;
                for (ll ck = ok; ck < ci + 1; ck += K) {
                    subTri[layerCount][elementCount] = tri[ci][ck];
                    elementCount++;
                } 
                layerCount++;
            }
            subTriMeta.push_back(layerCount);
        }
    }

    forn(ttt, subTriC) {
        forn(a, 513) forn(b, 3) {
            dpCost[a][b].push_back(0);
            dpNeg[a][b].push_back(0);
            forn(c, 3) {
                dpNum[a][b][c].push_back(0);
            }
        }
        ll minNum[3], minCost[3];
        forn(a, 3) {
            minNum[3] = LONG_MAX; 
            minCost[3] = LONG_MAX;
        }
        for (ll num = 1; num <= 512; num++) {
            ll cost[3] = {0};
            ll abcL = 0;
            forn(i, subTriMeta[ttt]) {
                ll abcE = abcL;
                forn(k, i + 1) {
                    ll diff = num - subTri[i][k][ttt];
                    if (diff > 0) {
                        cost[abcE] += diff * A;
                    } else if (diff < 0) {
                        cost[abcE] += -diff * B;
                    }
                    abcE = next(abcE);
                }
                abcL = next(abcE);
            }
            forn(a, 3) {
                if (cost[a] <= minCost[a]) {
                    minNum[a] = num;
                    minCost[a] = cost[a];
                }
                subTriCost[num][a] = cost[a];
            }
        }
        ll optSum = 0;
        forn(a, 3) optSum += minNum[a];
        for (ll sum = optSum + 1; sum <= 1537; sum++) {
            forn(abc, 3) {
                ll minCost = LONG_MAX;
                ll minAbc;
                forn(abc2, 3) {
                    if (dpNeg[sum - 1][abc2][ttt]) {
                        continue;
                    }
                    ll cost = 0;
                    forn(abc3, 3) {
                        ll num;
                        if (abc == abc3) {
                            num = dpNum[sum - 1][abc2][abc3][ttt] + 1;
                        } else {
                            num = dpNum[sum - 1][abc2][abc3][ttt];
                        }
                        cost += subTriCost[num][abc3][ttt];
                    }
                    if (cost <= minCost) {
                        minCost = cost;
                        minAbc = abc2;
                    }
                }
                forn(abc2, 3) {
                    if (abc2 == abc) {
                        num = dpNum[sum - 1][abc][abc2][ttt] + 1;
                    } else {
                        num = dpNum[sum - 1][abc][abc2][ttt];
                    }
                    dpNum[sum][abc][abc2][ttt] = num;
                    if (num < 1) {
                        dpNum[sum][abc][ttt] = true;
                    }
                }

            }
        }

        for (ll sum = optSum - 1; sum >= 3; sum--) {
            forn(abc, 3) {
                ll minCost = LONG_MAX;
                ll minAbc;
                forn(abc2, 3) {
                    if (dpNeg[sum + 1][abc2][ttt]) {
                        continue;
                    }
                    ll cost = 0;
                    forn(abc3, 3) {
                        ll num;
                        if (abc == abc3) {
                            num = dpNum[sum - 1][abc2][abc3][ttt] + 1;
                        } else {
                            num = dpNum[sum - 1][abc2][abc3][ttt];
                        }
                        cost += subTriCost[num][abc3][ttt];
                    }
                    if (cost <= minCost) {
                        minCost = cost;
                        minAbc = abc2;
                    }
                }
                forn(abc2, 3) {
                    if (abc2 == abc) {
                        num = dpNum[sum - 1][abc][abc2][ttt] + 1;
                    } else {
                        num = dpNum[sum - 1][abc][abc2][ttt];
                    }
                    dpNum[sum][abc][abc2][ttt] = num;
                    if (num < 1) {
                        dpNum[sum][abc][ttt] = true;
                    }
                }
            }
        }

    }

}