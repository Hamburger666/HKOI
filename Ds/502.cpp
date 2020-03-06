#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

ifstream fin; ll minCost = LONG_MAX, maxCost = 0;
int main() {
    fin.open("weather.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> words;
        string s;
        while (ss >> s) {
            words.push_back(s);
        }
        ll n = stoll(words[words.size()-2], NULL, 10);
        if (n < minCost) {
            minCost = n;
        }
        if (n > maxCost) {
            maxCost = n;
        }
    }
    cout << minCost << " " << maxCost << endl;

}