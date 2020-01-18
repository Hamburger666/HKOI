#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
using namespace std;

int N, A, B, K;
int triangle[80][80];
vector<int> subTriangle[80][80], subTriangle_N, subTriangle_startLayer, subTriangle_startElement; int subTriangle_count;
vector<int> cost[513][3];
vector<int> minCostAgg_dp[1537][3], minNum_dp[1537][3][3];
vector<bool> minValid_dp[1537][3];
int newTriangle[80][80];

void next(int &a) {
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
    bool triangleTranslated[80][80] = {0};
    subTriangle_count = 0;
    forn(layer, N) forn(element, layer + 1) if (!triangleTranslated[layer][element]) {
        forn(a, 80) forn(b, 80) subTriangle[a][b].push_back(0);
        subTriangle_startLayer.push_back(layer); subTriangle_startElement.push_back(element);
        int layer_from = layer;
        int layer_to = 0;
        while (layer_from < N) {
            int element_from = element; int element_to = 0;
            while (element_from < layer_from + 1) {
                subTriangle[layer_to][element_to][subTriangle_count] = triangle[layer_from][element_from];
                triangleTranslated[layer_from][element_from] = true;
                element_to++; element_from+=K;
            }
            layer_to++; layer_from+=K;
        }
        subTriangle_count++; subTriangle_N.push_back(layer_to);
    }

    form(a, 1536) {
        forn (b, 3) {
            minCostAgg_dp[a][b].resize(subTriangle_count);
            minValid_dp[a][b].resize(subTriangle_count);
            forn(c, subTriangle_count) minValid_dp[a][b][c] = true;
            forn(c, 3) {
                minNum_dp[a][b][c].resize(subTriangle_count);
            }
        }
    }


    form(a, 512) {
        forn(b, 3) {
            cost[a][b].resize(subTriangle_count);
        }
    }


    forn(subTriangle_id, subTriangle_count) if (subTriangle_N[subTriangle_id] != 1) {
        form(num, 512) {
            int abcL = 0;
            forn(layer, subTriangle_N[subTriangle_id]) {
                int abcE = abcL;
                forn(element, layer + 1) {
                    int diff = num - subTriangle[layer][element][subTriangle_id];
                    if (diff > 0) cost[num][abcE][subTriangle_id] += diff * A;
                    else if (diff < 0) cost[num][abcE][subTriangle_id] += -diff * B;
                    next(abcE);
                } 
                next(abcL);
            }
        }


        forn(a, 3) {
            forn(b, 3) {
                minCostAgg_dp[3][a][subTriangle_id] += cost[1][b][subTriangle_id];
                minNum_dp[3][a][b][subTriangle_id] = 1;
            }
        }


        for (int sum = 4; sum <= 1536; sum++) {
            forn(abc, 3) {
                int minAbc2, minCost = INT_MAX; 
                forn(abc2, 3) if (minNum_dp[sum - 1][abc2][abc][subTriangle_id] < 512 && minValid_dp[sum - 1][abc2][subTriangle_id]){
                    int costU = 0;
                    forn(abc3, 3) {
                        int num = minNum_dp[sum - 1][abc2][abc3][subTriangle_id];
                        if (abc == abc3) num++;
                        costU += cost[num][abc3][subTriangle_id];
                    }
                    if (costU < minCost) {
                        minCost = costU;
                        minAbc2 = abc2;
                    }
                }
                minValid_dp[sum][abc][subTriangle_id] = (minCost != INT_MAX);
                minCostAgg_dp[sum][abc][subTriangle_id] = minCost;
                forn(abc3, 3) {
                    int num = minNum_dp[sum - 1][minAbc2][abc3][subTriangle_id];
                    if (abc == abc3) num++;
                    minNum_dp[sum][abc][abc3][subTriangle_id] = num;
                }
            }
        }
    }

    int minCost = INT_MAX, minSum, minAbc[subTriangle_count];
    for (int sum = 3; sum <= 1536; sum++) {
        int costU = 0, abc[subTriangle_count];
        forn(subTriangle_id, subTriangle_count) {
            int minCost2 = INT_MAX, minAbc2;
            if (subTriangle_N[subTriangle_id] == 1) {
                int diff = sum - subTriangle[0][0][subTriangle_id];
                if (diff < 0) minCost2 = -diff * B;
                else minCost2 = 0;
            } else {
                forn(abc, 3) if (minValid_dp[sum][abc][subTriangle_id] && minCostAgg_dp[sum][abc][subTriangle_id] < minCost2) {
                    minCost2 = minCostAgg_dp[sum][abc][subTriangle_id];
                    minAbc2 = abc;
                }
            }
            costU += minCost2;
            abc[subTriangle_id] = minAbc2;
        }
        if (costU < minCost) {
            minCost = costU;
            minSum = sum;
            forn(i, subTriangle_count) minAbc[i] = abc[i];
        }
    }


    forn (subTriangle_id, subTriangle_count) {
        int layer_to = subTriangle_startLayer[subTriangle_id];
        int abcL = 0;
        if (subTriangle_N[subTriangle_id] == 1) {
            if (minSum < subTriangle[0][0][subTriangle_id]) {
                newTriangle[subTriangle_startLayer[subTriangle_id]][subTriangle_startElement[subTriangle_id]] = minSum;
            } else {
                newTriangle[subTriangle_startLayer[subTriangle_id]][subTriangle_startElement[subTriangle_id]] = subTriangle[0][0][subTriangle_id];
            }
        } else {
            forn(layer, subTriangle_N[subTriangle_id]) {
                int element_to = subTriangle_startElement[subTriangle_id];
                int abcE = abcL;
                forn(element, layer + 1) {
                    newTriangle[layer_to][element_to] = minNum_dp[minSum][minAbc[subTriangle_id]][abcE][subTriangle_id];
                    element_to += K; next(abcE);
                }
                layer_to += K; next(abcL);
            } 
        }
    }


    cout << minCost << endl;
    forn(layer, N) {
        forn(element, layer + 1) {
            cout << newTriangle[layer][element] << " ";
        }
        cout << endl;
    }
    

}