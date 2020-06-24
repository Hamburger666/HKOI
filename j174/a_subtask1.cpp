# include <iostream>
# define forn for (long long i = 0; i < n; i++)
# define MAX_X 20
using namespace std;
typedef long long ll;
ll X, Y, K;

bool board[MAX_X][MAX_X] = {0};

bool check(ll min_x, ll max_x, ll min_y, ll max_y) {
  pair<ll, ll> cursor;
  cursor.first = min_x;
  cursor.second = min_y;
  ll dotCount = 0;
  for (ll i = min_x; i <= max_x; i++) {
    if (board[cursor.first][cursor.second]) {
      dotCount++;
    }  
    cursor.first++;
    cursor.second++;
  }
  cursor.first = min_x;
  cursor.second = max_y;
  for (ll i = min_x; i <= max_x; i++) {
    if (board[cursor.first][cursor.second]) {
      dotCount++;
    }
    cursor.first++;
    cursor.second--;
  }
  return (dotCount == K);
}

int main() {
  cin >> X >> Y >> K;
  for (ll i = 0; i < X; i++) { 
    ll x, y;
    cin >> x >> y;
    board[x][y] = true;
  } 
  ll crossCount = 0;
  for (ll min_x = 0; min_x < X; min_x++) {
    for (ll min_y = 0; min_y < Y; min_y++) {
      for (ll length = 1; length <= min(X - min_x, Y - min_y); length++) {
        ll max_x = min_x + length;
        ll max_y = min_y + length;
        cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;
        if (check(min_x, max_x, min_y, max_y)) crossCount++;
      }
    }
  }
  cout << crossCount << endl;
}
