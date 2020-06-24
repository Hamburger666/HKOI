// a bit of waste of time so didn't finish 
#include <iostream>
#include <unordered_set>
typedef long long ll;
using namespace std;
ll X, Y, K;
#define MAX_N 1000001
unordered_set<ll> points;

int encode(pair<ll, ll> ps) {
  return ps.first * MAX_N + ps.second;
}

pair<ll, ll> decode(ll n) {
  pair<ll, ll> ps;
  ps.first = n / MAX_N;
  ps.second = n % MAX_N;
  return ps;
}

bool check(pair<ll, ll> lower, pair<ll, ll> upper) {
  ll count = 0;
  unordered_set<ll> countedPoints;
  pair<ll, ll> cursor;
  cursor.first = lower.first;
  cursor.second = lower.second;
  for (ll i = 0; i <= lower.first - upper.first; i++) {
    if (points.find(encode(cursor)) != points.end()) {
      count++;
      countedPoints.insert(encode(cursor));
    }
    cursor.first++;
    cursor.second++;
  }
  cursor.first = lower.first;
  cursor.second = upper.second;
  for (ll i = 0; i <= lower.first - upper.first; i++) {
    if (points.find(encode(cursor)) != points.end() && countedPoints.find(encode(cursor)) != countedPoints.end()) {
      count++;
    }
    cursor.first++;
    cursor.second--;
  }
  return (count == K);
}

int main() {
  cin >> X >> Y >> K;
}
