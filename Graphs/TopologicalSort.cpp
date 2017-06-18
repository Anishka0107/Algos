#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// for directed acyclic graphs only
// it has atleast 1 vertex with indegree 0 and 1 with outdegree 0
class Graph {
        vector<vector<int>> adjlst;
        vector<bool> visited;
    public:
        Graph (int);
        void insert_edge (int, int);
        void topo_sort();
        void topo_helper (stack<int> &, int);
};

Graph :: Graph (int v) {
    adjlst.resize (v);
    visited.resize (v);
}

void Graph :: insert_edge (int s, int d) {
    adjlst[s].push_back(d);
}

void Graph :: topo_sort() {
    stack<int> s;
    for (int i = 0; i < adjlst.size(); i++) {
        if (!visited[i])
            topo_helper (s, i);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void Graph :: topo_helper (stack<int> & s, int v) {
    visited[v] = true;
    for (auto i : adjlst[v]) {
        if (!visited[i])
            topo_helper (s, i);
    }
    s.push (v);
}

int main() {
    int v, e, s, d;
    // Enter number of vertices
    // Enter number of edges
    // Enter the edges in form of source-destination pairs for the directed graph
    cin >> v >> e;
    Graph g (v);
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        g.insert_edge (s, d);
    }
    // Prints the topological sort
    g.topo_sort();
    return 0;
}
