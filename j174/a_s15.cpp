#include <iostream>
#include <unordered_set>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;


ll X, Y, K;
ll suC[2000001] = {0}, difC[2000001] = {0};
unordered_set<ll> points;
ll ans = 0;

ll ep(pair<ll, ll> p) {
    return p.first * (Y+1) + p.second;
}

pair<ll, ll> dp(ll n) {
    pll p;
    p.first = n / (Y+1);
    p.second = n % (Y+1);
    return p;
}

bool hp(pair<ll, ll> p) {
    return points.find(ep(p)) != points.end();
}