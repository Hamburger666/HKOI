# include <iostream>
using namespace std;
typedef long long ll;
# define forn(i, n) for (long long i = 0; i < n; i++)

ll X, Y, K;

int main() {
  cin >> X >> Y >> K;
  ll count = 0;
  for (ll size = 1; size <= min(X, Y); size++) {
    count += (X - size + 1) * (Y - size + 1);
  }  
  cout << count << endl;
}
