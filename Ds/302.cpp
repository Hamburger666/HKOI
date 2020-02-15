#include <iostream>
#include <string>
using namespace std;

string s;
int main() {
	getline(cin, s);
	cout << s.length() << endl;
	int i = 0;
	for (char c : s) {
		if (c == ' ') i++;
	}
	cout << i + 1 << endl;
}