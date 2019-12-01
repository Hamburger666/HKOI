#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

#define forn(i, n) for (long long i = 0; i < n; i++)

long long W[2], K, P[2][2], d[2];
bool u[2];
bool turnBefore[2], turnAfter[2], turnMiddle[2], underShoot[2];
long long h[2], k[2], j[2];

void load() {
    forn (i, 2) cin >> W[i];
    cin >> K;
    forn (p, 2) forn (c, 2) cin >> P[p][c];
    forn (p, 2) forn (c, 2) P[p][c]--;

    //process input
    forn (c, 2) {
        if (P[0][c] > P[1][c]) {
            d[c] = P[0][c] - P[1][c];
            u[c] = false;
        } else {
            d[c] = P[1][c] - P[0][c];
            u[c] = true;
        }
    }
}

bool inRange(long long v,long long c) {
    return (v >= 0 && v < W[c]);
}

long long addAbsChange(long long v, long long change, long long c) {
    return (v + change * (u[c] ? 1 : -1));
}

string getDirWord(int c, bool u) {
    if (c) {
        if (u) return "right"; else return "left";
    } else {
        if (u) return "down"; else return "up";
    }
}

int main() {
    load();
    forn (c, 2) {
        h[c] = d[c] / K;
        k[c] = d[c] - h[c] * K ;
        j[c] = h[c] * K + K - d[c];
        turnBefore[c] = (inRange(addAbsChange(P[0][c], -j[c], c), c));
        turnAfter[c] = (inRange(addAbsChange(P[1][c], j[c], c), c));
        turnMiddle[c] = (h[c] >= 1);
        if (h[c]) {
            if (turnBefore[c] || turnAfter[c]) {
                underShoot[c] = ((1 + k[c]) < (1 + j[c]));
            } else if (turnMiddle[c]) {
                underShoot[c] = ((1 + k[c]) < (2 + j[c]));
            } else {
                underShoot[c] = true;
            }
        } else {
            if (turnBefore[c] || turnAfter[c]) {
                underShoot[c] = (k[c] < (1 + j[c]));
            } else {
                underShoot[c] = true;
            }
        }
        printf("change before = %lld\n", addAbsChange(P[0][c], -j[c], c));
    }
    long long total = 0;
    forn (c, 2) {
        if (underShoot[c]) {
            if (h[c]) total++;
            total += k[c];
        } else {
            if (turnBefore[c] || turnAfter[c]) {
                total += 1 + j[c];
            } else if (turnMiddle[c]) {
                total += 2 + j[c];
            } else throw runtime_error("");
        }
    }
    cout << total << endl;
    forn (c, 2) {
        if (underShoot[c]) {
            if (h[c]) cout << getDirWord(c, u[c]) << " " << h[c]*K << endl;
            forn(i, k[c]) cout << getDirWord(c, u[c]) << " " << 1 << endl;
        } else {
            if (turnBefore[c] || turnAfter[c]) {
                if (turnBefore[c]) forn(i, j[c]) cout << getDirWord(c, !u[c]) << " " << 1 << endl;
                cout << getDirWord(c, u[c]) << " " << h[c] * K + K << endl;
                if (turnAfter[c] && !turnBefore[c]) forn(i, j[c]) cout << getDirWord(c, !u[c]) << " " << 1 << endl;
            } else if (turnMiddle[c]) {
                cout << getDirWord(c, u[c]) << " " << K << endl;
                forn(i, j[c]) cout << getDirWord(c, !u[c]) << " " << 1 << endl;
                cout << getDirWord(c, u[c]) << " " << h[c]*K << endl;
            } else throw runtime_error("");
        }
    }
}