#include <iostream>
#include <cmath>
using namespace std;

bool ok(int queens[], int c) {
    for (int i = 0; i < c; i++) {
        if (queens[i] == queens[c] || (c - i) == abs(queens[c] - queens[i])) {
            return false;
        }
    }
    return true;
}

int nqueens (int n) {
    int numSolutions = 0;
    int* queens = new int[n];
    int c = 0;
    queens[0] = 0;
    while (c >= 0) {
        c++;
        if (c == n) {
            numSolutions++;
            c--;
        }
        else {
            queens[c] = -1;
        }
        while (c >= 0) {
            queens[c]++;
            if (queens[c] == n) {
                c--;
            } else {
                if (ok(queens,c)) break;
            }
        }
    }
    delete[] queens;
    return numSolutions;
}

int main() {
    int n;
    cout << "Enter a number of queens: ";
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem." << endl;
    }
    return 0;
}