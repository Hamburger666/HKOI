#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	cin >> s;
	char s2[s.length()];
	for (int i = 0; i < s.length(); i++) {
		s2[s.length() - 1 - i] = s[i];
	}
	string s2s(s2, s2 + s.length());
	cout << s2s << endl;
	if (s == s2s) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}