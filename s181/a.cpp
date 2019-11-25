#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
//left is positive
long long N, L, R, A[100000];
bool direction;
const bool right_ = true;
const bool left_ = false;
bool P[100000];
const bool even = true;
const bool odd = false;
void load() {
    cin >> N >> L >> R;
    forn(i, N) {
        cin >> A[i];
    }
}
void processLoad() {
    long long oddNo = 0;
    if (R < L) {
        direction = right_;
    } else {
        direction = left_;
    }
    forn(i, N) {
        if (A[i] % 2){
            oddNo++;
            P[i] = false;
        } else {
            P[i] = true;
        }
    }
    if (oddNo % 2) {
        cout << -1 << endl;
        exit(0);
    } else if (!oddNo) {
        cout << 0 << endl;
        exit(0);
    }
    // printf("direction = %s, right = %d, left = %d\n", (direction ? "right" : "left"), R, L);
    // forn(i, N) {
    //     cout << (P[i] ? "even" : "odd") << " ";
    // }
    // cout << endl;
}
long long getNextIndex(long long index) {
    long long pending = index + (direction ? -1 : 1);
    if (pending == -1) {
        return N-1;
    } else if (pending == N) {
        return 0;
    } else {
        return pending;
    }
}
long long distance(long long a, long long b) {
    return (min(abs(a - b), N - abs(a - b)));
}
int main() {
    load();
    processLoad();
    long long candinateTotalTime[2];
    forn(i, 2) {
        candinateTotalTime[i] = 0;
    }
    forn(i, 2) {
        // cout << i << endl;
        long long startingIndex = 0;
        forn(k, i+1) {
            startingIndex = getNextIndex(startingIndex);
            while (P[startingIndex]) {
                startingIndex = getNextIndex(startingIndex);
            }
        }
        // printf("startingIndex = %lld\n", startingIndex);
        long long previousOdd = 0;
        bool oneDown = false;
        long long index = startingIndex;
        do {
            // cout << "index = " << index << endl;
            if (!P[index]) {
                if (oneDown) {
                    // printf("previousOdd = %d, index = %d\n", previousOdd, index);
                    // printf("distance = %d\n", distance(index, previousOdd));
                    candinateTotalTime[i] += distance(index, previousOdd) * (direction ? R : L);
                    oneDown = false;
                } else {
                    previousOdd = index;
                    oneDown = true;
                }
            }
            index = getNextIndex(index);
        } while (index != startingIndex);
    }
    // printf("candidates: one = %d, two = %d\n", candinateTotalTime[0], candinateTotalTime[1]);
    cout << min(candinateTotalTime[0], candinateTotalTime[1]) << endl;
    return 0;
}