#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
        vector<vector<int>> adjlst;
        vector<bool> visited;
    public:
        Graph (int);
        void insert_edge (int, int);
        void DFS (int);
        void recur_DFS (int);
        void recur_DFS_helper (int);
};

Graph :: Graph (int v) {
    adjlst.resize (v);
    visited.resize (v);
}

void Graph :: insert_edge (int s, int d) {
    adjlst[s].push_back (d);
}

void Graph :: DFS (int start) {
    stack<int> s;
    s.push (start);
    while (!s.empty()) {
        start = s.top();
        s.pop();
        if (!visited[start]) {
            visited[start] = true;
            cout << start << " ";
        }
        for (auto i : adjlst[start]) {
            if (!visited[i])
                s.push (i);
        }
    }
    for (int i = 0; i < adjlst.size(); i++) {
        if (!visited[i])
            DFS (i);
    }
}

void Graph :: recur_DFS (int start) {
    recur_DFS_helper (start);
    for (int i = 0; i < adjlst.size(); i++) {
        if (!visited[i])
            recur_DFS_helper (i);
    }
}

void Graph :: recur_DFS_helper (int start) {
    visited[start] = true;
    cout << start << " ";
    for (auto i : adjlst[start]) {
        if (!visited[i])
            recur_DFS_helper (i);
    }
}

int main() {
    int v, e, s, d;
    cout << "Enter the number of vertices : ";
    cin >> v;
    Graph g (v);
    cout << "Enter the number of edges : ";
    cin >> e;
    cout << "Now, enter the edges :\n";
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        g.insert_edge (s, d);
    }
    cout << "Enter the starting vertex : ";
    cin >> s;
    cout << "The depth first search traversal of the graph is : ";
    g.DFS (s);
    // cout << "DFS (recursively done) : ";
    // g.recur_DFS (s);
    return 0;
}
