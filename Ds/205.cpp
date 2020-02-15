#include <iostream>
#include <cmath>
#define forn(i, n) for (long long i = 0; i<n; i++)
#define forr(i, a, b) for (long long i = a; i < b; i++)
typedef long long ll;
using namespace std;

ll N, n;
bool p[100000];
ll factors[100]; ll fc = 0;

int main() {
	cin >> N;
	n = N;
	ll i = 2;
	while(n != 1 && i < 100000) {
		if (!p[i]) { // if this is a prime number
			ll k = i * 2;
			while(k < 100000) {
				p[k] = true;
				k += i;
			}
			while (n % i == 0) {
				factors[fc++] = i;
				n /= i;
			}
		}
		i++;
	}

	cout << N << "=";
	if (fc) cout << factors[0];
	forr(i, 1, fc) {
		cout << "*" << factors[i];
	}
	if (n != 1){
		if(fc) cout << "*" << n;
		else cout << n;
	}
	cout << endl;
}