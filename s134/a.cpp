#include <iostream>
#include <vector>
#include <unordered_set>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N;
ll last, s, aSum, bSum;
vector<ll> a;
unordered_set<ll> as;
vector<ll> b;

int main() {
    a.reserve(500000);
    b.reserve(500000);
    cin >> N;
    if (N == 1) {
        cout << "1" << endl;
    } else if (N == 2) {
        cout << "2 1" << endl;
    } else if (N == 3) {
        cout << "1 2 3" << endl;
    } else {
        if ((N + 1)/2 % 2 == 1) {
            last = (N-1) / 2 * 2 + 1;
        } else {
            last = N / 2 * 2;
        }
        s = last * (last - 1) / 2;
        if (last != N) {
            s += N;
        }
        aSum = 0;
        ll k = last - 1;
        while (aSum < s/2) {
            a.push_back(min(k, s/2 - aSum));
            as.insert(min(k, s/2 - aSum));
            aSum += min(k, s/2 - aSum);
            k--;
        }
        forn(_, N) {
            ll i = _ + 1;
            if (as.find(i) == as.end() && i != last) {
                b.push_back(i);
            }
        }
        ll ai = 0;
        ll bi = 0;
        aSum = 0;
        bSum = 0;
        forn(i, N-1) {
            if (bSum < aSum) {
                cout << b[bi] << " ";
                bSum += b[bi];
                bi++;
            } else {
                cout << a[ai] << " ";
                aSum += a[ai];
                ai++;
            }
        }
        cout << last << endl;
    }
}