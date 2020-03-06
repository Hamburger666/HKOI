#include <iostream>
#include <string>
#define forn(i,n) for(long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll o[26] = {0};
ll N;
string s;
int main() {
    cin >> s;
    cin >> N;
    forn(i, s.length()) {
        o[s[i] - 'A']++;
    }
    forn(i, N) {
        ll ot[26] = {0};
        string st;
        cin >> st;
        bool yes = true;
        forn(i, st.length()) {
            ot[st[i] - 'A']++;

            if (ot[st[i] - 'A'] > o[st[i] - 'A']) {
                yes = false;
                break;
            }
        }
        if (yes) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}