#include <iostream>
#include <algorithm>
#define forn(i,n) for(long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;

string s; pair<char, ll> sc[300000]; ll cmap[100];
int main() {
    cin >> s;
    forn(i, s.length()) {
        sc[i].first=s[i];
        sc[i].second=i;
    }
    sort(sc, sc+s.length());
    forn(i, s.length()) {
        cmap[sc[i].first] = i;
    }
    ll at = sc[cmap['.']].second;
    string re(s.length(), '_');
    forn(i, s.length()) {
        char c = sc[at].first;
        re[i] = c;
        at = sc[at].second;
    }
    cout << re << endl;
}