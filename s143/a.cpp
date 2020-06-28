#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <functional>
#include <vector>
using namespace std;
#define forn(i, n) for(long long i = 0; i < n; i++)
typedef long long ll;

string d[20000];
unordered_map<size_t, vector<ll> > ss[50];
hash<string> shasher;
ll N, L, W;
int main() {
    ll _;
    cin >> N >> L;
    forn(i, N) {
        cin >> d[i];
        string n = d[i].substr(1);
        forn(j, L) {
            ss[j][shasher(n)].push_back(i);
            n[j] = d[i][j];
        }
    }
    cin >> W;
    forn(i, W) {
        string s;
        cin >> s;
        string n = s.substr(1);
        forn(j, L) {
            if (ss[j].find(shasher(n)) != ss[j].end()) for (ll i : ss[j][shasher(n)]) {
                if (d[i] != s) {
                    cout << d[i] << endl;
                    break;
                }
            }
            n[j] = s[j];
        }
    }
}