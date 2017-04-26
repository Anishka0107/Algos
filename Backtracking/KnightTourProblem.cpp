#include <iostream>
#define N 4
using namespace std;

int knight_tour[N][N] = {0};                  // marking all positions as unvisited
int positions[8][2] = { {1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2} };

bool is_valid_move (int i, int j) {
    if (i >= 0 && i < N && j >= 0 && j < N && knight_tour[i][j] == 0)
        return true;
    else
        return false;
}

bool visit (int move_number, int i, int j) {
    if (move_number == N*N)
        return true;
    for (int k = 0; k < 8; k++) {
        int next_x = i + positions[k][0];
        int next_y = j + positions[k][1];
        if (is_valid_move (next_x, next_y)) {
            knight_tour[next_x][next_y] = move_number + 1;
            if (visit (move_number+1, next_x, next_y) == true)
                return true;
            else
                knight_tour[next_x][next_y] = 0;
        }
    }
    return false;
}

int main() {
    knight_tour[0][0] = 1;       // since this is the starting position of the knight it is already visited
    cout << "For a chessboard of " << N*N << " squares with " << N << " knights, the solution is : \n";
    if (visit (1, 0 ,0) == true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << knight_tour[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Sorry, the knight cannot visit all squares...";
    return 0;
}
