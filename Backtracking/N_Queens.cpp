#include <bits/stdc++.h>
#define N 11
using namespace std;

bool is_valid_move (int queens[N][N], int row, int col) {
    // check col in all the rows above
    for (int i=0; i<row; i++) {
        if (queens[i][col] == 1)
            return false;
    }
    // check the upper left diagonal
    for (int i=row, j=col; i >= 0 && j >= 0; i--, j--) {
        if (queens[i][j] == 1)
            return false;
    }
    // check the upper right diagonal
    for (int i=row, j=col; i >= 0 && j < N; i--, j++) {
        if (queens[i][j] == 1)
            return false;
    }
    return true;
}

bool nqueens (int queens[N][N], int row) {
    if (row >= N)
        return true;
    for (int i=0; i<N; i++) {
        if (is_valid_move (queens, row, i)) {
            queens[row][i] = 1;
            if (nqueens (queens, row+1))
                return true;
            queens[row][i] = 0;
        }
    }
    return false;
}

int main() {
    int queens[N][N] = {0};
    if (nqueens (queens, 0)) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++)
                cout << queens[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Sorry!";
    return 0;
}
