#include <iostream>
#include <string>
#include <stdexcept>
#define forn(i, n) for(long long i = 0; i < n; i++)
using namespace std;
// d is dimension
long long W[2], K, S[2][2];
long long distance_[2], h[2], r[2], m[2];
bool upright[2], turn[2];
int strategy[2];
const int goUnder = 1;
const int goOver = 2;
const int turnback = 3;

bool isInRange(long long coordinate, int d) {
    // printf("test in rage: %lld, return %d\n", coordinate, ((coordinate >= 0) && (coordinate < W[d])));
    return ((coordinate >= 0) && (coordinate < W[d]));
}

long long add(long long coordinate, long long add, bool upright) {
    if(upright) {
        return (coordinate + add);
    } else {
        return (coordinate - add);
    }
}

string getCommandWord(int d, bool upright) {
    if(d) {
        if (upright) return "right"; else return "left";
    } else {
        if (upright) return "down"; else return "up";
    }
}

int main() {
    forn(i, 2) cin >> W[i];
    cin >> K;
    forn(p, 2) forn(d, 2) cin >> S[p][d];
    forn(p, 2) forn(d, 2) S[p][d]--;
    forn(d, 2) {
        if (S[0][d] <  S[1][d]) {
            upright[d] = true;
            distance_[d] = S[1][d] - S[0][d];
        } else {
            upright[d] = false;
            distance_[d] = S[0][d] - S[1][d];
        }
    }
    forn(d, 2) {
        h[d] = distance_[d]/K;
        r[d] = distance_[d] - h[d] * K;
        m[d] = h[d] * K + K - distance_[d];
        // printf("add(coord = %lld, -m[d] = %lld, upright[d] = %d)\n", S[0][d], -m[d], upright[d]);
        turn[d] = (W[d] - 1 >= h[d] * K + K); 

        if (h[d] == 0) {
            if (turn[d]) {
                if (m[d] + 1 < r[d]) strategy[d] = goOver;
                else strategy[d] = goUnder;
            } else {
                strategy[d] = goUnder;
            }
        } else {
            if (turn[d]) {
                if (m[d] < r[d]) strategy[d] = goOver;
                else strategy[d] = goUnder;
            } else {
                if (m[d] + 1 < r[d]) strategy[d] = turnback;
                else strategy[d] = goUnder;
            }
        }
    }


    long long count = 0;
    forn(d, 2) {
        if (h[d] == 0) {
            if (strategy[d] == goUnder) forn(i, r[d]) count++;
            else { 
                long long pos = add(S[0][d], -1, upright[d]);
                long long remaining = m[d];
                while (isInRange(pos, d) && remaining > 0) {
                    count++;
                    pos = add(pos, -1, upright[d]);
                    remaining--;
                }
                count++;
                while (remaining > 0) {
                    count++;
                    remaining--;
                }
            }
        } else {
            if (strategy[d] == goUnder) {
                count++;
                forn(i, r[d]) count++;
            } else if (strategy[d] == goOver) {
                long long pos = add(S[0][d], -1, upright[d]);
                long long remaining = m[d];
                while (isInRange(pos, d) && remaining > 0) {
                    count++;
                    pos = add(pos, -1, upright[d]);
                    remaining--;
                }
                count++;
                while (remaining > 0) {
                    count++;
                    remaining--;
                }
            } else if (strategy[d] == turnback) {
                count++;
                forn(i, m[d]) count++;
                count++;
            }
        }
    }

    cout << count << endl;

    forn(d, 2) {
        // printf("strategy = %d\n", strategy[d]);
        if (h[d] == 0) {
            if (strategy[d] == goUnder) forn(i, r[d]) cout << getCommandWord(d, upright[d]) << " 1" << endl;
            else { 
                long long pos = add(S[0][d], -1, upright[d]);
                long long remaining = m[d];
                while (isInRange(pos, d) && remaining > 0) {
                    cout << getCommandWord(d, !upright[d]) << " 1" << endl;
                    pos = add(pos, -1, upright[d]);
                    remaining--;
                }
                cout << getCommandWord(d, upright[d]) << " " << h[d] * K + K << endl;
                while (remaining > 0) {
                    cout << getCommandWord(d, !upright[d]) << " 1" << endl;
                    remaining--;
                }
            }
        } else {
            if (strategy[d] == goUnder) {
                cout << getCommandWord(d, upright[d]) << " " << h[d] * K << endl;
                forn(i, r[d]) cout << getCommandWord(d, upright[d]) << " 1" << endl;
            } else if (strategy[d] == goOver) {
                long long pos = add(S[0][d], -1, upright[d]);
                long long remaining = m[d];
                while (isInRange(pos, d) && remaining > 0) {
                    cout << getCommandWord(d, !upright[d]) << " 1" << endl;
                    pos = add(pos, -1, upright[d]);
                    remaining--;
                }
                cout << getCommandWord(d, upright[d]) << " " << h[d] * K + K << endl;
                while (remaining > 0) {
                    cout << getCommandWord(d, !upright[d]) << " 1" << endl;
                    remaining--;
                }
            } else if (strategy[d] == turnback) {
                cout << getCommandWord(d, upright[d]) << " " << K << endl;
                forn(i, m[d]) cout << getCommandWord(d, !upright[d]) << " 1" << endl;
                cout << getCommandWord(d, upright[d]) << " " << h[d] * K << endl;
            }
        }
    }

    
    return 0;
}