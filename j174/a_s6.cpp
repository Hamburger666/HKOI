# include <iostream>
using namespace std;
typedef long long ll;

ll X, Y, K;

int main() {
  cin >> X >> Y >> K;
  ll x, y;
  cin >> x >> y;
  ll count =  
    (
     (min(x, y) + 1) * 
     (min(X-x, Y-y) + 1)) + 
    (
     (min(x, Y-y) + 1) * 
     (min(X-x, y) + 1)
    ) - 
    (min(min(x, y), min(X - x, Y - y))) - 2;
  cout << count;
}
