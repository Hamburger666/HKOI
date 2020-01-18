#include <iostream>
#include <vector>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define form(i, n) for (int i = 1; i <= n; i++)
using namespace std;

int N, A, B, K;
int triangle[80][80];
int triangle_filled[80][80] = {0};
int subTriangle_layer[1620], subTriangle_element[1620]; int subTriangle_count = 0;
int singletons_layer[3240], singletons_element[3240]; int singletons_count = 0;
int costTable[513][3][1620];
int minCost_dp[1537][3][1620], minNum_dp[1537][3][3][1620], minInvalid_dp[1537][3][1620];
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

    

    forn(layer, N) forn(element, layer + 1) if (!triangle_filled[layer][element]) {
        bool isSingleton = (layer + K >= N);
        if (isSingleton) {
            singletons_layer[singletons_count] = layer;
            singletons_element[singletons_count] = element;
            singletons_count++;
        } else {
            subTriangle_layer[subTriangle_count] = layer;
            subTriangle_element[subTriangle_count] = element;

            form(num, 512){
                int dl = 0;
                for (int subLayer = layer; subLayer < N; subLayer += K){
                    int de = dl;
                    for (int subElement = element; subElement < subLayer + 1; subElement += K) {
                        triangle_filled[subLayer][subElement] = true;
                        int diff = num - triangle[subLayer][subElement];
                        if (diff > 0) costTable[num][de][subTriangle_count] += A * diff;
                        else if (diff < 0) costTable[num][de][subTriangle_count] += B * -diff;
                        next(de);
                    }
                    next(dl);
                }
            }
            forn(d, 3) {
                forn(d2, 3) {
                    minCost_dp[3][d][subTriangle_count] += costTable[1][d2][subTriangle_count];
                    minNum_dp[3][d][d2][subTriangle_count] = 1;
                }    
            }            
            for (int sum = 4; sum <= 1536; sum++) {
                forn(d, 3) {
                    int minCost = INT_MAX, minD2 = 0;
                    forn(d2, 3) if (minNum_dp[sum - 1][d2][d][subTriangle_count] < 512 && !minInvalid_dp[sum - 1][d2][subTriangle_count]) {
                        int cost = 0;
                        forn(d3, 3) {
                            int num = minNum_dp[sum - 1][d2][d3][subTriangle_count];
                            if (d == d3) num++;
                            cost += costTable[num][d3][subTriangle_count];
                        }
                        if (cost <= minCost) {
                            minCost = cost;
                            minD2 = d2;
                        }
                    }
                    minCost_dp[sum][d][subTriangle_count] = minCost;
                    forn(d3, 3) {
                        int num = minNum_dp[sum - 1][minD2][d3][subTriangle_count];
                        if (d == d3) num++;
                        minNum_dp[sum][d][d3][subTriangle_count] = num;
                    }
                    minInvalid_dp[sum][d][subTriangle_count] = (minCost == INT_MAX);
                }
            }
            subTriangle_count++;
        }
    }
    
    long long minCost = INT_MAX, minSum, minD[subTriangle_count];
    for (int sum = 3; sum <= 1536; sum++) {
        int cost = 0, ds[subTriangle_count];
        forn(subTriangle_id, subTriangle_count) {
            int minCost2 = INT_MAX, minD2;
            forn(d, 3) if (!minInvalid_dp[sum][d][subTriangle_id] && minCost_dp[sum][d][subTriangle_id] < minCost2) {
                minCost2 = minCost_dp[sum][d][subTriangle_id];
                minD2 = d;
            }
            cost += minCost2;
            ds[subTriangle_id] = minD2;
        }
        forn(singletons_id, singletons_count) {
            int diff = sum - triangle[singletons_layer[singletons_id]][singletons_element[singletons_id]];
            if (diff < 0) {
                cost += B * -diff;
            }
        }
        if (cost <= minCost) {
            minCost = cost;
            minSum = sum;
            forn(i, subTriangle_count) minD[i] = ds[i];
        }
    }

    forn(subTriangle_id, subTriangle_count) {
        int dl = 0;
        for (int layer_to = subTriangle_layer[subTriangle_id]; layer_to < N; layer_to += K) {
            int de = dl;
            for (int element_to = subTriangle_element[subTriangle_id]; element_to < layer_to + 1; element_to += K) {
                newTriangle[layer_to][element_to] = minNum_dp[minSum][minD[subTriangle_id]][de][subTriangle_id];
                next(de);
            }
            next(dl);
        }
    }
    
    forn(singleton_id, singletons_count) {
        int num;
        if (minSum < triangle[singletons_layer[singleton_id]][singletons_element[singleton_id]]) num = minSum;
        else num = triangle[singletons_layer[singleton_id]][singletons_element[singleton_id]];
        newTriangle[singletons_layer[singleton_id]][singletons_element[singleton_id]] = num;
    }


    cout << minCost << endl;
    forn(layer, N) {
        forn(element, layer + 1) {
            cout << newTriangle[layer][element] << " ";
        }
        cout << endl;
    }


    
    forn(subTriangle_id, subTriangle_count) for (int sum = 3; sum <= 1536; sum++) {
        forn(d, 3) {
            bool isOver = false;
            forn(d2, 3) {
                if (minNum_dp[sum][d][d2][subTriangle_id] > 512) isOver = true;
            }
            if (isOver != minInvalid_dp[sum][d][subTriangle_id]) throw runtime_error("");
        }
    }

    cout << minNum_dp[384][0][0][0] << " ";
    cout << minNum_dp[384][0][1][0] << " ";
    cout << minNum_dp[384][0][2][0] << " " << endl;

    cout << minNum_dp[384][1][0][0] << " ";
    cout << minNum_dp[384][1][1][0] << " ";
    cout << minNum_dp[384][1][2][0] << " " << endl;

    cout << minNum_dp[384][2][0][0] << " ";
    cout << minNum_dp[384][2][1][0] << " ";
    cout << minNum_dp[384][2][2][0] << " " << endl;

    cout << "-----------" << endl;

    cout << minNum_dp[383][0][0][0] << " ";
    cout << minNum_dp[383][0][1][0] << " ";
    cout << minNum_dp[383][0][2][0] << " " << endl;

    cout << minNum_dp[383][1][0][0] << " ";
    cout << minNum_dp[383][1][1][0] << " ";
    cout << minNum_dp[383][1][2][0] << " " << endl;

    cout << minNum_dp[383][2][0][0] << " ";
    cout << minNum_dp[383][2][1][0] << " ";
    cout << minNum_dp[383][2][2][0] << " " << endl;

    cout << "-----------" << endl;



    forn(a, 3) {
        forn(b, 3) {
            cout << minNum_dp[385][a][b][0] << " ";
        }
        cout << endl;
    }

    forn(a, 3) {
        cout << minCost_dp[385][a][0] << endl;
    }
}