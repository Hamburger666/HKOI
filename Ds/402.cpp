#include <iostream>
#include <string>
#include <unordered_map>
#define forn(i,n) for (long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll N, M;
unordered_map<string, ll> p;
int main() {
    cin >> N;
    forn(i, N) {
        string bar;
        cin >> bar;
        string pp;
        cin >> pp;
        pp.erase(pp.end()-2);
        ll price = stoll(pp, nullptr, 10);
        p[bar] = price;
    }
    cin >> M;
    ll total = 0;
    forn(i, M) {
        string bar;
        cin >> bar;
        total += p[bar];
    }
    string totalS = to_string(total);
    totalS.insert(totalS.end()-1, '.');
    cout << totalS << endl;

}