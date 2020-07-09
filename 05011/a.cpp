/*
define DP(i): the min number of coins needed to get exactly i.
DP(i) = min( DP(i - coin[j]) for j from 0 to n-1 )

def DP(m):
  for j in range(n):
    try all DP(m - coin[j]) and return the minimum
    remember the immediate next coin you're supposed to pick to       get the optimal outcome
*/
#include <iostream>
#define forn(i, n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll M, N;
ll coins[100];
ll mcm[10001];  // set this all to -1, for this problem 0 is actually okay but don't take the chance in competition
ll cs[10001] = {0};
// mc(m): there is only 1 optimal solution, and that solution corresponds with a choice of a particular coin.
// and you need remember the coin of choice with a particular solution to DP[m]
ll mc(ll m) {
    if (m == 0) {
        return 0;
    }
    if (mcm[m] != -1) {
        return mcm[m];
    }
    ll minD = 10001;
    ll minDC;
    forn(i, N) {
        ll m2 = m - coins[i];
        if (m2 >= 0) {
            if (mc(m2) + 1 < minD) {
                minD = mc(m2) +1;
                minDC = i;
            }
        }
    }
    cs[m] = minDC;
    // save the result into the DP memoization array here:
    mcm[m] = minD;
    return minD;
}

int main() {
    cin >> M >> N;
    forn(i, N) {
        cin >> coins[i];
    }
    forn(i, M + 1) {
        mcm[i] = -1;
    }
    ll minD = mc(M);
    cout << minD << endl;
    ll ch[100] = {0};
    ll m = M;
    while (m != 0) {
        ch[cs[m]]++;
        m -= coins[cs[m]];
    }
    forn(i, N) {
        cout << ch[i] << endl;
    }
    return 0;
}
