#include <iostream>
using namespace std;

int subtaskNo, n4, n6, n9, dollars;
int largestNugget69(int remainingDollars) {
    int maxN6_count = remainingDollars / n6;
    int largestNugget = 0;
    for (int n6_count = 0; n6_count <= maxN6_count; n6_count++) {
        int n9_count = (remainingDollars - n6_count * n6) / n9;
        int currentNugget = n6_count * 6 + n9_count * 9;
        if (currentNugget > largestNugget) { 
            largestNugget = currentNugget;
        }
    }
    return largestNugget;
}
int largestNugget() {
    int maxN4_count = dollars / n4;
    int largestNugget = 0;
    for (int n4_count = 0; n4_count <= maxN4_count; n4_count++) {
        int currentNugget = n4_count * 4 + largestNugget69(dollars - n4_count * n4);
        if (currentNugget > largestNugget) {
            largestNugget = currentNugget;
        }
    }
    return largestNugget;
}


int main() {
    cin >> subtaskNo >> n4 >> n6 >> n9 >> dollars;
    cout << largestNugget() << endl;
}