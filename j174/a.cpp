#include <iostream>
#include <vector>
#include <stdexcept>
#define forn(i, n) for (long long i = 0; i < n; i++)
#define form(i, n) for (long long i = 1; i <= n; i++)
typedef long long ll;
using namespace std;

ll X, Y, K;
vector<pair<ll, ll> > b[2];
pair<ll, ll> a[2];
bool as[2] = {0};

void printp(pair<ll, ll> p) {
    cout << "[" << p.first << ", " << p.second << "]" << endl;
}

void d(pair<ll, ll>& p) {
    p.first *= 2;
    p.second *= 2;
}

ll s(pair<ll, ll> p0_min, pair<ll, ll> p0_max, pair<ll, ll> p1_min, pair<ll, ll> p1_max) {
    pair<ll, ll> center;
    center.first = (p1_min.first + p1_min.second - p0_min.second + p0_min.first) / 2;
    center.second = (p1_min.first + p1_min.second + p0_min.second - p0_min.first) / 2;
    ll r = min(center.first, min(center.second, min(X - center.first, Y - center.second)));
    if (r <= 0) {
        return 0;
    }
    pair<ll, ll> lower_corner;
    pair<ll, ll> upper_corner;
    lower_corner.first = center.first - r;
    lower_corner.second = center.second - r;
    upper_corner.first = center.first + r;
    upper_corner.second = center.second + r;
    ll re = max(0ll, min(p0_min.first - lower_corner.first, min(upper_corner.first - p0_max.first, min(p1_min.first - lower_corner.first, upper_corner.first - p1_max.first)))/2 + 1);
    return re;
}

bool pt(pair<ll, ll> p) {
    if (a[0].first - p.first == a[0].second - p.second) {
        b[0].push_back(p);
        return true;
    } else if (a[1].first - p.first == p.second - a[1].second) {
        b[1].push_back(p);
        return true;
    } else if (!as[0]) {
        as[0] = true;
        a[0] = p;
        b[0].push_back(p);
        return true;
    } else if (!as[1]) {
        as[1] = true;
        a[1] = p;
        b[1].push_back(p);
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> X >> Y >> K;
    X *= 2;
    Y *= 2;
    if (K == 0) {
        ll re = 0;
        forn(i, min(X/2, Y/2)) {
            re += (X/2 - i) * (Y/2 - i);
        }
        cout << re << endl;
        return 0;
    } else if (K == 1) {
        pair<ll, ll> p;
        cin >> p.first >> p.second;
        d(p);
        ll re = (min(p.first, p.second)/2 + 1) * (min(X - p.first, Y - p.second)/2 + 1) + (min(p.first, Y - p.second)/2 + 1) * (min(p.second, X - p.first)/2 + 1) - min(p.first, min(p.second, min(X - p.first, Y - p.second)))/2 - 2;
        cout << re << endl;
        return 0;
    } else if (K == 2) {
        throw runtime_error("");
        pair<ll, ll> p[2];
        cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second;
        d(p[0]);
        d(p[1]);
        if (p[0].first - p[1].first == p[0].second - p[1].second) {
            ll re = (min(p[0].first, min(p[0].first, min(p[1].first, p[1].first)))/2 + 1) * (min(X - p[0].first, min(Y - p[0].second, min(X - p[1].first, Y - p[1].second)))/2 + 1);
            cout << re << endl;
            return 0;
        } else if (p[0].first - p[1].first == p[1].second - p[0].second) {
            ll re = (min(p[0].first, min(Y - p[0].second, min(p[1].first, Y - p[1].second)))/2 + 1) * (min(p[0].second, min(X - p[0].first, min(p[1].second, X - p[1].first)))/2 + 1);
            cout << re << endl;
            return 0;
        } else {
            ll re = s(p[0], p[0], p[1], p[1]) + s(p[1], p[1], p[0], p[0]);
            cout << re << endl;
            return 0;
        }
    } else {
        pair<ll, ll> ps[3];
        forn(i, 3) {
            cin >> ps[i].first >> ps[i].second;
            d(ps[i]);
        }
        bool success = false;
        forn(i, 3) {
            if (ps[i].first - ps[(i + 1) % 3].first == ps[i].second - ps[(i + 1) % 3].second) {
                as[0] = true;
                a[0] = ps[i];
                b[0].push_back(ps[i]);
                form(k, 2) {
                    if (!pt(ps[(i+k) % 3])) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
                success = true;
                break;
            }
            if (ps[i].first - ps[(i + 1) % 3].first == ps[(i + 1) % 3].second - ps[i].second) {
                as[1] = true;
                a[1] = ps[i];
                b[i].push_back(ps[i]);
                form(k, 2) {
                    if (!pt(ps[(i + k) % 3])) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
                success = true;
                break;
            }
        }
        if (!success) {
            cout << 0 << endl;
            return 0;
        }
        forn(_, K-3) {
            ll i = _ + 3;
            pair<ll, ll> p;
            cin >> p.first >> p.second;
            d(p);
            if (!pt(p)) {
                cout << 0 << endl;
                return 0;
            }
        }
        pair<ll, ll> p0_max, p0_min, p1_max, p1_min;
        p0_max.first = 0;
        p0_min.first = X;
        p1_max.first = 0;
        p1_min.first = X;
        for (pair<ll, ll> p : b[0]) {
            if (p.first >= p0_max.first) {
                p0_max = p;
            }
            if (p.first <= p0_min.first) {
                p0_min = p;
            }
        }
        for (pair<ll, ll> p : b[1]) {
            if (p.first >= p1_max.first) {
                p1_max = p;
            }
            if (p.first >= p1_min.first) {
                p1_min = p;
            }
        }
        cout << s(p0_min, p0_max, p1_min, p1_max) << endl;
        return 0;
    }
}