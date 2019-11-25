#include <iostream>
#include <stdexcept>
using namespace std;

long long one, two, three;
long long A, B, M;
void load() {
    cin >> one >> two >> three;
}

// case 1: if the change is positive (one of them)
// case 2: if all changes are negative 
// case 3: if the changes are 0
// case 4: impossible

void case4() {
    cout << "No solution" << endl;
    exit(0);
}

void printCase() {
    cout << A << " " << B << " " << M << endl;
    exit(0);
}

void case1() {
    if (two - one < 0 || three - two < 0) {
        if (two - one > 0) {
            A = two - one;
            if (three > A - 1) {
                case4();
            }
            long long pendingThree = two + A;
            M = pendingThree - three;
            B = one - A;
            if (B < 0) {
                B += M;
            }
            printCase();
        } else {
            A = three - two;
            if (two > A - 1) {
                case4();
            }
            long long pendingTwo = one + A;
            M = pendingTwo - two;
            B = one - A;
            if (B < 0) {
                B += M;
            }
            printCase();
        }
    } else {
        if (two - one == three - two) {
            A = two - one;
            B = one - A;
            M = three + 1;
            if (B < 0) {
                B = B + M;
            }
            printCase();
        } else {
            case4();
        }
    }
}

void case2() {
    if (two - one == three - two) {
        M = one + 1;
        A = M + two - one;
        B = one - A;
        if (B < 0) {
            B += M;
        }
        printCase();
    } else {
        case4();
    }
}

void case3() {
    A = 0;
    B = one;
    M = one + 1;
    printCase();
}


int main() {
    load();
    if (two - one > 0 || three - two > 0) {
        case1();
    } else if (two - one < 0 && three - two < 0) {
        if (two - one == three - two) {
            case2();
        } else {
            case4();
        }
    } else if (one == two || two == three) {
        if (one == three) {
            case3();
        } else {
            case4();
        }
    } else {
        throw runtime_error("");
    }
}
