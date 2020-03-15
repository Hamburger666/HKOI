#include <iostream>
#include <stack>
#include <string>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

stack<ll> d;
ll N;

int main() {
    cin >> N;
    forn(i, N) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            ll n;
            cin >> n;
            d.push(n);
        } else if (s == "TOP") {
            if (!d.empty()) {
                cout << d.top() << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (s == "POP") {
            if (!d.empty()) {
                d.pop();
            } else {
                cout << "Cannot pop" << endl;
            }
        } else if (s == "SIZE") {
            cout << d.size() << endl;
        }
    }
}