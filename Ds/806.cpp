#include <iostream>
using namespace std;
typedef long long ll;

ll N;
void r(ll left, ll right) {
    if (right - left <= 1) {
        return;
    }
    ll mid = (right + left + 1) /2;
    r(left, mid);
    r(mid, right);
    cout << left+1 << " " << mid << " " << mid + 1 << " " << right << endl;;
}
int main() {
    cin >> N;
    r(0, N);
}