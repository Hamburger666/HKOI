#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <bitset>
#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
using namespace std;


char mode; 
ll N, M;
vector<vector<ll> > cities;
vector<ll> solution;
vector<ll> sendInts;
vector<ll> bi;
string receiveBitsS;
bitset<7> encode3(ll a, ll b, ll c) {
    ll d = a*25 + b*5 + c;
    bitset<7> e(d);
    return e;
}
void decode3(bitset<7> bs, ll& a, ll& b, ll& c) {
    ll d = bs.to_ullong(); 
    a = d / 25;
    b = d % 25 / 5;
    c = d % 5;
}
void populate5(ll p, ll i, bool first) {
    solution[i] = p*2 + first;
    for(ll w : cities[i]) {
        if (cities[w].size() >= 10 && bi[w] == p && solution[w] == -1) {
            populate5(p, w, !first);
        }
    }
}
int main() {
    cin >> mode;
    cin >> N >> M;
    cities.resize(N);
    solution.reserve(N);
    forn(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cities[a].push_back(b);
        cities[b].push_back(a);
    }
    if (mode == 'A') {
        solution.reserve(N);
        forn(i, N) {
            ll a;
            cin >> a;
            a--;
            solution.push_back(a);
        }
        forn(i, N) {
            if (cities[i].size() >= 10) {
                sendInts.push_back(solution[i]/2);
            }
        }
        while(sendInts.size() % 3 != 0) {
            sendInts.push_back(0);
        }
        forn(i, sendInts.size()/3) {
            bitset<7> bs = encode3(sendInts[i*3], sendInts[i*3+1], sendInts[i*3+2]);
            cout << bs;
        }
        cout << endl;
    } else if (mode == 'B') {
        ll _;
        cin >> _;
        cin >> receiveBitsS;
        sendInts.reserve(receiveBitsS.size() / 7 * 3);
        if (_) forn(i, receiveBitsS.size()/7) {
            bitset<7> bs(receiveBitsS.substr(i*7, 7));
            ll a, b, c;
            decode3(bs, a, b, c);
            sendInts.push_back(a);
            sendInts.push_back(b);
            sendInts.push_back(c);
        }
        bi.resize(N);
        ll si = 0;
        forn(i, N) {
            if (cities[i].size() >= 10) {
                bi[i] = sendInts[si];
                si++;
            }
        }
        solution.resize(N, -1);
        forn(i, N) {
            if (cities[i].size() >= 10 && solution[i] == -1) {
                populate5(bi[i], i, true);
            }
        }
        forn(i, N) {
            bool f[10] = {0};
            if (solution[i] == -1) {
                for(ll w : cities[i]) {
                    if (solution[w] != -1) {
                        f[solution[w]] = true;
                    }
                }
                ll k;
                forn(i, 10) {
                    if (!f[i]) {
                        k = i;
                        break;
                    }
                }
                solution[i] = k;
            } 
        }

        forn(i, N) {
            cout << solution[i] + 1 << " ";
        }
        cout << endl;
    } else {
        throw runtime_error("unsupported mode");
    }
}