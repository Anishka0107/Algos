#include <bits/stdc++.h>
#define MAX 20
using namespace std;

int adjmat[MAX][MAX];
static int n;

void initialize() {
    cout << "Enter the number of vertices : ";
    cin >> n;
    cout << "Enter the edges :\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjmat[i][j];
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
}

void insert_vertex() {
    if (n < MAX) {
        n++;
        for (int i = 0; i < n; i++) {
            adjmat[i][n-1] = 0;
            adjmat[n-1][i] = 0;
        }
        cout << "Vertex inserted is : " << n << "\n";
    }
    else {
        cout << "Graph full! Cannot insert more vertices!\n";
    }
}

void insert_edge (int src, int dest) {
    if (src <= 0 || src > n || dest <= 0 || dest > n) {
        cout << "Invalid pair of vertices! Cannot create edge!\n";
        return;
    }
    adjmat[src-1][dest-1] = 1;
}

void delete_vertex (int v) {
    if (v <= 0 || v > n) {
        cout << "Vertex does not exist!\n";
        return;
    }
    for (int i = v-1; i < n-1; i++)
        for (int j = 0; j < n; j++)
            adjmat[i][j] = adjmat[i+1][j];
    for (int i = 0; i < n; i++)
        for (int j = v-1; j < n-1; j++)
            adjmat[i][j] = adjmat[i][j+1];
    n--;
} 

void delete_edge (int src, int dest) {
    if (src <=0 || src > n || dest <= 0 || dest > n || adjmat[src-1][dest-1] == 0) {
        cout << "Edge does not exist!\n";
        return;
    }
    adjmat[src-1][dest-1] = 0;
}

int main() {
    initialize();
    cout << "MENU :\n\t1. Insert vertex\n\t2. Insert edge\n\t3. Delete vertex\n\t4. Delete edge\n\t5. Print graph\n\t6. Exit\n";
    while (true) {
        int ch, s, d;
        cout << "Enter your choice : ";    
        cin >> ch;
        switch (ch) {
            case 1:
                insert_vertex();
                break;
            case 2:
                cout << "Enter the edge : ";
                cin >> s >> d;
                insert_edge (s, d);
                break;
            case 3:
                cout << "Enter the vertex to be deleted : ";
                cin >> s;
                delete_vertex (s);
                break;
            case 4:
                cout << "Enter the edge to be deleted : ";
                cin >> s >> d;
                delete_edge (s, d);
                break;
            case 5:
                print_graph();
                break;
            case 6:
                return 0;
            default:
                cout << "Wrong choice entered!\n";
        }
    }
    return 0;
}
