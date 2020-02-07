#include <iostream>
#include <unordered_map>
#include <sstream>
#define forn(i, n) for (long long i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

ll N, M;
unordered_map<string, string> d;

void printlist(string *list, ll size) {
    forn(i, size) {
        cout << list[i] << ", ";
    }
    cout << endl;
}

void printlist(ll *list, ll size) {
    forn(i, size) {
        cout << list[i] << ", ";
    }
    cout << endl;
}

int main() {
    cin >> N;
    forn(i, N) {
        string a, b;
        cin >> a >> b;
        d[a] = b;
    }



    cin >> M;
    string t;
    getline(cin, t);
    forn(i, M) {
        string s, p, q;
        getline(cin, s);
        getline(cin, p);
        getline(cin, q);
        unordered_map<char, ll> sd;
        forn(i, q.length()) {
            sd[q.at(i)] = i;
        }
        ll ds[26];
        forn(i, p.length()) {
            ds[i] = sd[p.at(i)];
        }
        stringstream ss(s);
        string sl[26];
        ll w = 0;
        while(ss) {
            ss >> sl[w++];
        }
        
        string so[26];
        forn(k, q.length()) {
            if (d.find(sl[k]) != d.end()) {
                so[ds[k]] = d[sl[k]];
            } else {
                so[ds[k]] = sl[k];
            }
        }

        forn(k, q.length()) {
            cout << so[k] << " ";
        }

        cout << endl;

    }


}