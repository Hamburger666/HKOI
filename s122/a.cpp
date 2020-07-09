#include <iostream>
#include <vector>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pair<pll, pll> rectangles[1000]; //{{xMin, yMin}, {xMax, yMax}}

ll area(pll minP, pll maxP) {
    return (maxP.first - minP.first) * (maxP.second - minP.second);
}

ll perimeter(pll minP, pll maxP) {
    return ((maxP.first - minP.first) + (maxP.second - minP.second)) * 2;
}

ll toothPickC(pll minP, pll maxP) {
    return (area(minP, maxP) * 2 + perimeter(minP, maxP) / 2);
}

int main() {
    cin >> N;
    forn(i, N) {
        cin >> rectangles[i].first.first >> rectangles[i].first.second >> rectangles[i].second.first >> rectangles[i].second.second;
    }
    ll c = 0;
    forn(i, N) {
        c += toothPickC(rectangles[i].first, rectangles[i].second);
        forn(j, i) {
            if (
                rectangles[i].first.first == rectangles[j].first.first ||
                rectangles[i].first.first == rectangles[j].second.first ||
                rectangles[i].second.first == rectangles[j].first.first ||
                rectangles[i].second.first == rectangles[j].second.first
            ) {
                c -= max(
                    0ll, 
                    min(
                        min(                            
                            rectangles[i].second.second - rectangles[j].first.second, 
                            rectangles[j].second.second - rectangles[i].first.second
                        ),
                        min(
                            rectangles[i].second.second - rectangles[i].first.second,
                            rectangles[j].second.second - rectangles[j].first.second
                        )
                    )
                );
            }
            if (
                rectangles[i].first.second == rectangles[j].first.second ||
                rectangles[i].first.second == rectangles[j].second.second ||
                rectangles[i].second.second == rectangles[j].first.second ||
                rectangles[i].second.second == rectangles[j].second.second
            ) {
                c -= max(
                    0ll, 
                    min(
                        min(
                            rectangles[i].second.first - rectangles[j].first.first, 
                            rectangles[j].second.first - rectangles[i].first.first
                        ),
                        min(
                            rectangles[i].second.first - rectangles[i].first.first,
                            rectangles[j].second.first - rectangles[j].first.first
                        )
                    )
                );
            }
        }
    }
    cout << c << endl;
    return 0; 
}