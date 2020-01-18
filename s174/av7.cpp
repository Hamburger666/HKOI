#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i < n; i++)

typedef long long ll;
using namespace std;

ll N, A, B, K;
ll triangle[80][80];
vector<ll> subTriangle[80][80], subTriangle_N; ll subTriangle_count;
vector<ll> cost[513][3], minCosts[3], minCostAgg, minNum[3];
vector<ll> minCostAgg_dp[1537][3], minNum_dp[1537][3][3], minAbc[1537];

void next(ll &a) {
    a++;
    if (a == 3) a = 0;
}
int main() {
    cin >> N >> A >> B >> K;
    forn(layer, N) {
        forn(element, layer + 1) {
            cin >> triangle[layer][element];
        }
    }

    ll triangleTranslated[80][80] = {0};
    subTriangle_count = 0;
    forn(layer, N) {
        forn(element, layer + 1) {
            if (!triangleTranslated[layer][element]) {
                forn(a, 80) forn(b, 80) subTriangle[a][b].push_back(0);
                ll layer_from = layer; ll element_from = element;
                ll layer_to = 0; ll element_to = 0;
                while (layer_from < N) {
                    while (element_from < layer_from + 1) {
                        subTriangle[layer_to][element_to][subTriangle_count] = triangle[layer_from][element_from];
                        triangleTranslated[layer_from][layer_from] = true;
                        element_to++; element_from+=4;
                    }
                    layer_to++; layer_from+=4;
                }
                subTriangle_count++; subTriangle_N.push_back(layer_to);
            }
        }
    }

    minCostAgg.resize(subTriangle_count);
    forn(a, 3) {
        minNum[a].resize(subTriangle_count); 
        minCosts[a].resize(subTriangle_count); 
        forn(b, 513) cost[b][a].resize(subTriangle_count);
        forn(b, subTriangle_count) minCosts[a][b] = LONG_MAX;
    }
    forn(a, 1537) {
        minAbc[a].resize(subTriangle_count);
        forn(b, 3) {
            minCostAgg_dp[a][b].resize(subTriangle_count);
            forn(c, 3) minNum_dp[a][b][c].resize(subTriangle_count);
        }
    }

    forn(subTriangle_id, subTriangle_count) {
        form(num, 512) {
            ll abcL = 0;
            forn(layer, subTriangle_N[subTriangle_id]) {
                ll abcE = abcL;
                forn(element, layer) {
                    ll diff = num - subTriangle[layer][element][subTriangle_id];
                    if (diff > 0) cost[num][abcE][subTriangle_id] += diff * A;
                    else if (diff < 0) cost[num][abcE][subTriangle_id] += -diff * B;
                    next(abcE);
                } 
                next(abcL);
            }
            forn(abc, 3) if (cost[num][abc][subTriangle_id] < minCosts[abc][subTriangle_id]) {
                minCosts[abc][subTriangle_id] = cost[num][abc][subTriangle_id]; 
                minNum[abc][subTriangle_id] = num;
            }
        }
        forn(abc, 3) minCostAgg[subTriangle_id] += minCosts[abc][subTriangle_id];
        ll optSum = 0; forn(a, 3) optSum += minNum[a][subTriangle_id];
        forn(a, 3) {
            minCostAgg_dp[optSum][a][subTriangle_id] = minCostAgg[subTriangle_id];
            forn(b, 3) {
                minNum_dp[optSum][b][a][subTriangle_id] = minNum[a][subTriangle_id];
            }
        }
        for (ll sum = optSum + 1; sum <= 1536; sum++) {
            forn(abc, 3) {
                ll minCost = LONG_MAX, minAbc2;
                forn(abc2, 3) if (minNum_dp[sum - 1][abc2][abc][subTriangle_id] < 512) {
                    ll cost;
                    forn(abc3, 3) {
                        ll num = minNum_dp[sum - 1][abc2][abc3][subTriangle_id];
                        if (abc3 == abc) {
                            num++;
                        }
                    }
                    if (cost < minCost) {
                        minCost = cost;
                        minAbc2 = abc2;
                    }
                }

                minCostAgg_dp[sum][abc][subTriangle_id] = minCost;
                forn(abc3, 3) {
                    ll num = minNum_dp[sum - 1][minAbc2][abc3][subTriangle_id];
                    if (abc == abc3) num++;
                    minNum_dp[sum][abc][abc3][subTriangle_id] = num;
                }
            }
        }
    }


}