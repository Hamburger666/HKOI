#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;

int N, M, L;
int C[100000], D[100000][86400];
bool P[100000]; int Q[100000],
T[100000], H[100000], B[100000],
Dp[100000][86400];
 
int main() {
    cin >> N >> M >> L;
    forn(i, N) {
        cin >> C[i];
        forn(j, C[i]) {
            cin >> D[i][j];
        } 
    }
    forn(i, M) {
        cin >> P[i] >> Q[i];
        Q[i]--;
    }
    forn(i, L) {
        cin >> T[i] >> H[i] >> B[i];
        H[i]--;
        B[i]--;
    }
    if (T[L-1] == 86400) L--;

    forn(i, N) {
        int currentTime = 0;
        int endTime;
        forn(j, C[i]) {
            endTime = currentTime + D[i][j];
            while (currentTime < endTime) {
                Dp[i][currentTime] = j;
                currentTime++;
            }
        }
    }
    return 0;
}
