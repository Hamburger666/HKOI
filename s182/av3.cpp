#include <iostream>
#include <string>
#define forn(i, n) for (int i = 0; i < n; i++) 
using namespace std;

int P[3], G[2][3], D, W, matchOutcome[3][3], Pc[3], Gc[2][3];

void load() {
    cin >> W >> D;
    forn(i, 3) {
        cin >> P[i];
        forn(k, 2) cin >> G[k][i];
    }
}

int main() {
    load();
    int upperBound, lowerBound;
    
    return 0;
}