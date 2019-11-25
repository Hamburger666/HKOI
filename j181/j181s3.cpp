#include <iostream>
#include <climits>
using namespace std; 

int subtaskNo, n4, n6, n9, numberOfNugget;

int smallestPrice69(int remainingPiece) {
    int smallestPrice = INT_MAX;
    int maxN6_count = remainingPiece / 6 + ((remainingPiece % 6 == 0) ? 0 : 1);
    for (int n6_count = 0; n6_count <= maxN6_count; n6_count++) {
        int n9_count = max(0, (remainingPiece - n6_count * 6)) / 9 + (((max(0,(remainingPiece - n6_count * 6))) % 9 == 0) ? 0 : 1);
        int currentPrice = n6_count * n6 + n9_count * n9;
        if (currentPrice < smallestPrice) {
            smallestPrice = currentPrice;
        }
    }
    return smallestPrice;
}

int smallestPrice() {
    int smallestPrice = INT_MAX;
    int maxN4_count = numberOfNugget / 4 + ((numberOfNugget % 4 == 0) ? 0 : 1);
    for (int n4_count = 0; n4_count <= maxN4_count; n4_count++) {
        int currentPrice = n4_count * n4 + smallestPrice69(max(0, numberOfNugget - n4_count * 4)); 
        if (currentPrice < smallestPrice) {
            smallestPrice = currentPrice;
        }
    }
    return smallestPrice;

}

int main() {
    cin >> subtaskNo >> n4 >> n6 >> n9 >> numberOfNugget;
    cout << smallestPrice() << endl;
    return 0;
}