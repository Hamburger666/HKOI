#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cmath>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

long long W[2], K;
long long A[2], B[2]; // 0 is r, 1 is c
long long d[2], bigStep[2];
bool flipped[2];
int strategy[2];
const int justRight = 1;
const int underShoot = 2;
const int overShootBefore = 3;
const int overShootAfter = 4;
const int overShootMiddle = 5;

void calcDistance() {
    forn(i, 2) {
        d[i] = abs(A[i] - B[i]);
        flipped[i] = (A[1] > B[i]);
    }
}

int getSign(bool flipped) {
    return (flipped ? -1 : 1);
}

string getWord(int orientatoinNo, bool flipped) {
    if (orientatoinNo == 0 && flipped) {
        return "up";
    } else if (orientatoinNo == 1 && flipped) {
        return "left";
    } else if (orientatoinNo == 0 && !flipped) {
        return "down";
    } else if (orientatoinNo == 1 && !flipped) {
        return "right";
    } else {
        throw runtime_error("");
    }
}

int inEdge(long long index, int orientatoinNo) {
    return(index>=0 && index < W[orientatoinNo]);
}

int main() {
    cin >> W[0] >> W[1] >> K >> A[0] >> A[1] >> B[0] >> B[1];
    forn(i, 2) {
        A[i]--;
        B[i]--;
    }
    calcDistance();
    forn(i, 2) {
        bigStep[i] = d[i] / K;
        if (d[i] % K == 0) {
            strategy[i] = justRight;
        } else {
            int backTrackPlace;
            int forwardNo;
            const int before = 1;
            const int middle = 2;
            const int after = 3;
            const int noOverShoot = 4;
            long long smallStep = bigStep[i] * K + K - d[i];
            if (inEdge(A[i] - smallStep * getSign(flipped[i]), i)) {
                forwardNo = 1;
                backTrackPlace = before;
            } else if(inEdge(B[i] + smallStep * getSign(flipped[i]), i)) {
                forwardNo = 1;
                backTrackPlace = after;
            } else if(bigStep >= (long long *)1) {
                forwardNo = 2;
                backTrackPlace = middle;
            } else {
                backTrackPlace = noOverShoot;
            }
            if (backTrackPlace == noOverShoot) {
                strategy[i] = underShoot;
            } else {
                if (forwardNo + smallStep < 1 + d[i] - bigStep[i] * K) {
                    if (backTrackPlace == before) {strategy[i] = overShootBefore;}
                    else if (backTrackPlace == after) {strategy[i] = overShootAfter;}
                    else if (backTrackPlace == middle) {strategy[i] = overShootMiddle;}
                } else {
                    strategy[i] = underShoot;
                }
            }
        }
    }
    int totalStep = 0;
    forn(i, 2) {
        if (strategy[i] == overShootBefore || strategy[i] == overShootAfter) {
            totalStep += 1 + bigStep[i] * K + K - d[i];
        } else if (strategy[i] == overShootMiddle) {
            totalStep += 2 + bigStep[i] * K + K - d[i];
        } else {
            totalStep += 1 + d[i] - bigStep[i] * K;
        }
    }
    cout << totalStep << endl;
    forn(i, 2) {
        long long middleLength;
        if (strategy[i] == overShootMiddle) {
            cout << getWord(i, flipped[i]) << " " << K << endl;
        } 
        if (strategy[i] == overShootBefore || strategy[i] == overShootMiddle) {
            forn(i, bigStep[i] * K + K - d[i]) {
                cout << getWord(i, !flipped[i]) << " 1" << endl;
            }
        }
        if (strategy[i] == overShootMiddle || strategy[i] == underShoot || strategy[i] == justRight) {
            cout << getWord(i, flipped[i]) << " " << bigStep[i] * K << endl;
        } else {
            cout << getWord(i, flipped[i]) << " " << bigStep[i] * K + K << endl;
        }
        if (strategy[i] == overShootAfter) {
            forn(i, bigStep[i] * K + K - d[i]) {
                cout << getWord(i, !flipped[i]) << " 1" << endl;
            }
        }
    }
}
