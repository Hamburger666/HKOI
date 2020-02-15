#include <iostream>
#include <cstring>
using namespace std;

string s; char a[20];
int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		a[i] = '_';
	}
	int guessed = 0;
	while(guessed < s.length()) {
		char letter;
		cin >> letter;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == letter) {
				a[i] = letter;
				guessed++;
			}
		}
		for (int i = 0; i < s.length(); i++) {
			cout << a[i];
		}
		cout << endl;
	}
}