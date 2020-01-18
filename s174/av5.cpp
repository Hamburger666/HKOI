#include "stdc++.h"
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++) 
#define form(i, n) for (long long i = 1; i <= n; i++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
typedef long long ll;


ll N, A, B, K;
ll ogTriangle[80][80];
bool fillTriangle[80][80] = {0};
vector<ll> subTriangles[80][80];
ll subTrianglesLayerCount[6400];
ll subTriangle_count;
ll optimalNum[80][3], optimalCost[80][3];
ll dp[80][513][3], num[80][513][3];
int main() {
    cin >> N >> A >> B >> K;
    forn(layer, N) {
        forn(element, layer + 1) {
            cin >> ogTriangle[layer][element];
        }
    }

    subTriangle_count = 0;
    forn(layer, N) {
        forn(element, layer + 1) {
            if (fillTriangle[layer][element]) {
                continue;
            }
            ll subElement = element;
            ll subLayer = layer;
            ll newElement = 0;
            ll newLayer = 0;
            forn(i, 80) forn(k, 80) {
                subTriangles[i][k].push_back(0);
            }
            while (subLayer < N) {
                subTriangles[newLayer][newElement][subElement] = ogTriangle[subLayer][subElement];
                fillTriangle[subLayer][subElement] = false;
                if (element + K > subLayer) {
                    subLayer += K;
                    subElement = element;
                    newLayer++;
                } else {
                    subElement += K;
                    newElement++;
                }
            }
            subTrianglesLayerCounts.push_back(newLayer);
            subTriangle_count++;
        }
    }

    forn(subTriangleId, subTriangle_count) {
        ll minCosts[3], minNum[3];
        form(x, 512) {
            ll costs[3] = {0};
            ll rowStartLetter = 0;
            ll letter = 0;
            forn(layer, subTrianglesLayerCount[x]) {
                forn(element, layer+1) {
                    ll diff = x - subTriangles[layer][element][subTriangleId];
                    if (diff > 0) {
                        costs[letter] += A * diff;
                    } else if (diff < 0) {
                        costs[letter] += B * diff;
                    }
                    letter++;
                    if (letter == 3) {
                        letter = 0;
                    }
                }
                rowStartLetter++;
                if (rowStartLetter == 3) { 
                    rowStartLetter = 0;
                }
                letter = rowStartLetter;
            }
            forn (i, 3) {
                if (costs[i] < minCosts[i]) {
                    minCosts[i] = costs[i];
                    minNum[i] = x;
                }
            }
        }
        forn(i, 3) {
            optimalNum[subTriangleId][i] = minNum[i];
            optimalCost[subTriangleId][i] = minCosts[i];
        }

        

    }

    

}