#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll T;
int main() {
    cin >> T;
    for (ll t = 0; t < T; t++) {
        ll r[10] = {0};
        string s;
        cin >> s;
        string b = "0" + s;
        // cout << b << endl;
        ll i = b.length()-1;
        while(b[i-1] >= b[i]) {
            ll n = b[i] - '0';
            r[n]++;
            i--;
        }
        // cout << "running " << i << endl;
        ll n = b[i] - '0';
        r[n]++;
        n = b[i-1] - '0';
        r[n]++;
        // cout << "n " << n << endl;
        n++;
        while (r[n] == 0) {
            n++;
        }
        ll w = i-1;
        // cout << "w " << w << endl;
        r[n]--;
        b[w] = '0' + n;
        w++;
        n=0;
        while(n < 10) {
            while(r[n] > 0) {
                b[w] = '0' + n;
                r[n]--;
                w++;
                // cout << "running w " << w << endl;
            }
            n++;
        }
        // cout << "w at the end " << w << endl;
        cout << "Case #" << t+1 << ": ";
        if (b[0] == '0') {
            cout << b.substr(1, s.length()) << endl;
        } else {
            cout << b << endl;
        }
    }
}