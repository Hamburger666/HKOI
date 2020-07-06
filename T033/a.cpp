#include <iostream>
#include <vector>
#include <queue>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define INF 50001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> cities[50]; // {two, distance}
ll N, M;
ll dist[2][50];

void dijkstra(ll source, ll u) { 
    forn(i, N) {
        forn(u, 2) {
            dist[u][i] = INF;
        }
    }
    priority_queue<pair<ll, pair<ll, bool> > > toFinalise; // {-dist, {city, 1 or two trip}}
    dist[u][source] = 0;
    toFinalise.push(make_pair(0, make_pair(source, u)));
    while(!toFinalise.empty()) {
        ll d = -toFinalise.top().first;
        ll one = toFinalise.top().second.first;
        bool u =  toFinalise.top().second.second;
        toFinalise.pop();
        if (d == dist[u][one]) {
            for (pll c : cities[one]) {
                ll two = c.first;
                ll d = c.second;
                if (u) {
                    d = d * 4 / 5;
                }
                if (d + dist[u][one] < dist[!u][two]) {
                    dist[!u][two] = d + dist[u][one];
                    toFinalise.push(make_pair(-dist[!u][two], make_pair(two, !u)));
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    forn(i, M) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        cities[a].push_back(make_pair(b, d));
        cities[b].push_back(make_pair(a, d));
    }
    dijkstra(0, 0);
    cout << min(dist[0][1], dist[1][1]) << endl;
    dijkstra(1, 0);
    cout << min(dist[0][0], dist[1][0]) << endl;
    return 0;
}