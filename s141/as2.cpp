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
bitset<10> encode3(ll a, ll b, ll c) {
    ll d = a*100 + b*10 + c;
    bitset<10> e(d);
    return e;
}
void decode3(bitset<10> bs, ll& a, ll& b, ll& c) {
    ll d = bs.to_ullong(); 
    a = d / 100;
    b = d % 100 / 10;
    c = d % 10;
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
                sendInts.push_back(solution[i]);
            }
        }
        while(sendInts.size() % 3 != 0) {
            sendInts.push_back(0);
        }
        forn(i, sendInts.size()/3) {
            bitset<10> bs = encode3(sendInts[i*3], sendInts[i*3+1], sendInts[i*3+2]);
            cout << bs;
        }
        cout << endl;
    } else if (mode == 'B') {
        ll _;
        cin >> _;
        cin >> receiveBitsS;
        sendInts.reserve(receiveBitsS.size() / 10 * 3);
        if (_) forn(i, receiveBitsS.size()/10) {
            bitset<10> bs(receiveBitsS.substr(i*10, 10));
            ll a, b, c;
            decode3(bs, a, b, c);
            sendInts.push_back(a);
            sendInts.push_back(b);
            sendInts.push_back(c);
        }
        solution.resize(N, -1);
        ll si = 0;
        forn(i, N) {
            if (cities[i].size() >= 10) {
                solution[i] = sendInts[si];
                si++;
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