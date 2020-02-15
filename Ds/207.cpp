#include <iostream>
using namespace std;

int a, b;
int lcm = 0, gcd = 0;
int main() {
	cin >> a >> b;
	int i = max(a, b);
	while(!lcm) {
		if (i%a == 0 && i%b==0) {
			lcm = i;
		}
		i++;
	}
	for (int i = max(a,b); i > 0; i--) {
		if (a%i == 0 && b%i==0) {
			gcd = i;
			break;
		}
	}
	cout << gcd << endl;
	cout << lcm << endl;
}