#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

long long W[2], P[2][2], d[2];
int K;
bool u[2];
int turn[2];
bool shootUnder[2];
long long bigStep[2];
int remainingUnder[2], remainingOver[2];
int totalStep = 0;

void load() {
    forn(i, 2) cin >> W[i];
    cin >> K;
    forn(i, 2) forn(j, 2) cin >> P[i][j];
    forn(i, 2) forn(j, 2) P[i][j]--;
    forn(i, 2) turn[i] = -1;
    // printf("w0 = %lld, w1 = %lld, k = %d, Ar = %lld, Ac = %lld, Br = %lld, Bc = %lld\n", W[0], W[1], K, P[0][0], P[0][1], P[1][0], P[1][1]);
}

void calcD() {
    forn(i, 2){
        d[i] = abs(P[0][i] - P[1][i]);
        u[i] = P[0][i] > P[1][i];
    }
}

long long getDp(long long dt, int u, int k) { return dt * (u ? 1 : -1) * (k ? -1 : 1); }

int inBound(long long p, int o) { 
    // printf("in inBound(): p = %lld\n", p);
    return (p >= 0 && p < W[o]); 
    }

string getWord(int o, int u) {
    if (o) {
        if (u) return "left"; else return "right";
    } else {
        if (u) return "up"; else return "down";
    }
}

int main() {
    load();
    calcD();
    forn(i, 2) {
        bigStep[i] = d[i] / K;
        remainingOver[i] = bigStep[i] * K + K - d[i];
        remainingUnder[i] = d[i] - bigStep[i] * K;
        // printf("bigStep = %lld, remainingOver = %d, remainingUnder = %d, d = % lld \n", bigStep[i], remainingOver[i], remainingUnder[i], d[i]);

        forn(k, 2) {        
            // printf("P[k][i] = % lld, dp = %lld\n", P[k][i], getDp(remainingOver[i], u[i], k));
            if (inBound(P[k][i] + getDp(remainingOver[i], u[i], k), i)) turn[i] = k; }
        // printf("turn = %d\n", turn[i]);
        if (turn[i] == -1) {
            if (bigStep[i] >= 1) {
                if (2 + remainingOver[i] < 1 + remainingUnder[i]) {
                    shootUnder[i] = false;
                    totalStep += 2 + remainingOver[i];
                } else {
                    shootUnder[i] = true;
                    totalStep += remainingUnder[i];
                }
            } else {
                shootUnder[i] = true;
                totalStep += 1 + remainingUnder[i];
            }
        } else {
            if (1 + remainingOver[i] < (bigStep[i] ? 1 : 0) + remainingUnder[i]) {
                shootUnder[i] = false;
                totalStep += 1 + remainingOver[i];
            } else {
                shootUnder[i] = true;
                totalStep += (bigStep[i] ? 1 : 0) + remainingUnder[i];
            }
        }
    }
    
    long long totalStep2 = 0;
    forn(o, 2) {
        if (!shootUnder[o] && turn[o] == -1) totalStep2++;
        if (!shootUnder[o] && (turn[o] == 0 || turn[o] == -1)) forn(i, remainingOver[o]) totalStep2++;
        int toPrint = (bigStep[o] + ((shootUnder[o] || turn[o] == -1) ? 0 : 1)) * K;
        if (toPrint) totalStep2++;
        if (shootUnder[o]) forn(i,remainingUnder[o]) totalStep2++;
        if (!shootUnder[o] && turn[o] == 1) forn(i, remainingOver[o]) totalStep2++;
    }
    cout << totalStep2 << endl;
    forn(o, 2) {
        if (!shootUnder[o] && turn[o] == -1) cout << getWord(o, u[o]) << " " << K << endl;
        if (!shootUnder[o] && (turn[o] == 0 || turn[o] == -1)) forn(i, remainingOver[o]) cout << getWord(o, !u[o]) << " 1" << endl;
        int toPrint = (bigStep[o] + ((shootUnder[o] || turn[o] == -1) ? 0 : 1)) * K;
        if (toPrint) {
            cout << getWord(o, u[o]) << " " << (bigStep[o] + ((shootUnder[o] || turn[o] == -1) ? 0 : 1)) * K << endl;
        }
        if (shootUnder[o]) forn(i,remainingUnder[o]) cout << getWord(o, u[o]) << " 1" << endl;
        if (!shootUnder[o] && turn[o] == 1) forn(i, remainingOver[o]) cout << getWord(o, !u[o]) << " 1" << endl;
    }
}