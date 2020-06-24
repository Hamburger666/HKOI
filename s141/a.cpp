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
    a = d/25;
    b = d % 25 / 5;
    c = d % 5;
}
void populate(ll p, ll i, bool first) {
    first = !first;
    solution[i] = p*2 + i;
    for (ll w : cities[i]) {
        if (solution[w] == -1 && bi[w] == p) {
            populate(p, w, first);
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
            cout << bs << endl;
        }
    } else if (mode == 'B') {
        ll _;
        cin >> _;
        cin >> receiveBitsS;
        if (_) forn(i, receiveBitsS.size()/7) {
            bitset<7> bs(receiveBitsS.substr(i*3, 7));
            ll a, b, c;
            decode3(bs, a, b, c);
            sendInts.push_back(a);
            sendInts.push_back(b);
            sendInts.push_back(c);
        }
        solution.resize(N, -1);
        forn(i, N) {
            bool f[10] = {0};
            if (cities[i].size() < 10) forn(k, cities[i].size()) {
                if (solution[cities[i][k]] != -1) {
                    f[solution[cities[i][k]]] = true;
                }
            } 
            ll w = -1;
            forn(i, 10) {
                if (!f[i]) {
                    w = i;
                    break;
                }
            }
            solution[i] = w;
        }
        ll si = 0;
        bi.resize(N);
        forn(i, N) {
            if (solution[i] == -1) {
                bi[i] = sendInts[si];
                si++;
            }
        }
        forn(p, 5) {
            ll i = 0;
            while((bi[i] != p || solution[i] != -1) && i < N) {
                i++;
            }
            if (i < N) {
                populate(p, i, true);
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