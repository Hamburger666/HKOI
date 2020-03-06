#include <iostream>
#include <queue>
#define forn(i,n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll N;
queue<ll> q;
int main() {
    cin >> N;
    forn(i, N) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            ll n;
            cin >> n;
            q.push(n);
        } else if (s == "FRONT") {
            if (!q.empty()) {
                cout << q.front() << endl;;
            } else {
                cout << "Empty" << endl;;
            }
        } else if (s == "POP") {
            if (!q.empty()) {
                q.pop();
            } else {
                cout << "Cannot pop" << endl;
            }
        } else if (s == "SIZE") {
            cout << q.size() << endl;
        }
    }
}