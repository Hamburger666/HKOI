using namespace std;
#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
#define forn(i, n) for(long long i = 0; i < n; i++)
typedef long long ll;

ll N, L, W;
string ss[20000];
unordered_map<ll, list<ll> > aa;
unordered_map<ll, list<ll> > bb;
int main() {
    cin >> N >> L;
    forn(i, N) {
        cin >> ss[i];
        ll akey = (ss[i][0] - 'a') * 26 * 26 + (ss[i][1] - 'a') * 26 + (ss[i][2] - 'a');
        ll bkey = (ss[i][3] - 'a') * 26 * 26 + (ss[i][4] - 'a') * 26 + (ss[i][5] - 'a');
        aa[akey].push_back(i);
        bb[bkey].push_back(i);
    }
    cin >> W;
    forn (i, W) {
        string s;
        cin >> s;
        ll akey = (s[0] - 'a') * 26 * 26 + (s[1] - 'a') * 26 + (s[2] - 'a');
        ll bkey = (s[3] - 'a') * 26 * 26 + (s[4] - 'a') * 26 + (s[5] - 'a');
        string ans;
        for (ll i : aa[akey]) {
            string n = ss[i];
            ll diff = 0;
            forn(j, L) {
                if (s[j] != n[j]) {
                    diff++;
                }
                if (diff > 1) {
                    break;
                }
            }
            if (diff == 1) {
                ans = n;
                break;
            }
        }
        for (ll i : bb[bkey]) {
            string n = ss[i];
            ll diff = 0;
            forn(j, L) {
                if (s[j] != n[j]) {
                    diff++;
                }
                if (diff > 1) {
                    break;
                }
            }
            if (diff == 1) {
                ans = n;
                break;
            }            
        }
        cout << ans << endl;
    }
}