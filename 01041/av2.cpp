#include <iostream>
#include <vector>
#include <queue>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 1000001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll source, dest;
vector<pll> cities[1000];
ll dist[1000];
ll pre[1000];

ll dijsktra(ll source) {
    forn(i, N) {
        dist[i] = INF;
    }
    priority_queue<pll, vector<pll>, greater<pll> > toFinalise; //{-dist, city}
    dist[source] = 0;
    toFinalise.push(make_pair(0, source));
    while(!toFinalise.empty()) {
        ll one = toFinalise.top().second;
        ll d = toFinalise.top().first;
        toFinalise.pop();
        if (d == dist[one]) {
            for (pll c : cities[one]) {
                ll two = c.first;
                ll d = c.second;
                if (d + dist[one] < dist[two]) {
                    dist[two] = d + dist[one];
                    pre[two] = one;
                    toFinalise.push(make_pair(dist[two], two));
                }
            }

        }
    }
}
int main() {
    cin >> N;
    cin >> source >> dest;
    source--;
    dest--;
    ll a, b, d;
    cin >> a >> b >> d;
    while(!(a == 0 && b == 0 && d == 0)) {
        a--;
        b--;
        cities[a].push_back(make_pair(b, d));
        cities[b].push_back(make_pair(a, d));
        cin >> a >> b >> d;
    }
    dijsktra(source);
    cout << dist[dest] << endl;
    vector<ll> path;
    ll k = dest;
    while (k != source) {
        path.push_back(k);
        k = pre[k];
    }
    path.push_back(source);
    for (ll i = path.size() - 1; i >=0; i--) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;
}