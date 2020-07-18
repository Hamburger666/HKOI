#include <iostream>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N, Q;
ll ns[300000];
ll nsp[300001];
ll gcdd[300000][300000];
ll gdc(ll a, ll b){
    if (a == 0) {
        return b;
    }
    return gdc(b%a, a);
}