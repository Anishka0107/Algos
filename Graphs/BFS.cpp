#include <iostream>
#include <queue>
#include <limits>
using namespace std;

// for directed unweighted graph
// for undirected, just insert edges accordingly
// for weighted graphs, just add the weight of the edge to distance vector instead of 1
class Graph {
        vector<vector<int>> adjlst;
        vector<bool> visited;
        vector<int> distance;
    public:
        Graph (int);
        void insert_edge (int, int);
        void BFS (int);
};

Graph :: Graph (int v) {
    adjlst.resize(v);
    visited.resize(v);
    distance.resize(v);
}

void Graph :: insert_edge (int s, int d) {
    adjlst[s].push_back (d);
}

void Graph :: BFS (int start) {
    queue<int> q;
    visited[start] = true;
    q.push (start);
    while (!q.empty()) {
        start = q.front();
        q.pop();
        cout << start << " at distance ";
        if (distance[start] != numeric_limits<int>::max())
            cout << distance[start] << endl;
        else
            cout << "INFINITY" << endl;
        for (auto i : adjlst[start]) {
            if (!visited[i]) {
                visited[i] = true;
                if (distance[start] != numeric_limits<int>::max())
                    distance[i] = distance[start] + 1;                
                else
                    distance[i] = numeric_limits<int>::max();
                q.push (i);
            }
        }
    }
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) {
            distance[i] = numeric_limits<int>::max();
            BFS (i);
        }
    }
}

/* 
 * For recursive implementation, the procedure is same, just that I would have to push the starting vertex into the queue before calling 
 * BFS function 
 *   mark starting vertex as visited
 *   push it into queue
 * and the function would have to call itself at the end :
 *   BFS():
 *     if q is not empty:
 *       pop front vertex
 *       visit popped vertex
 *       for every adjacent vertex of popped vertex:
 *         if this adjacent vertex is not visited:
 *           mark it as visited
 *           push it into queue
 *       BFS()
 * Very naive, not useful, still needs a queue. Unlike DFS which needs stack so can utilize the recursion stack. 
 */

int main() {
    int v, e, s, d;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "The vertices are : starting vertex - 0, ending vertex - " << v-1 << "\n";
    Graph g(v);
    cout << "Enter the number of edges : ";
    cin >> e;
    cout << "Now enter the edges :\n";
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        g.insert_edge (s, d);
    }
    cout << "Enter the starting edge : ";
    cin >> s;
    cout << "The breadh first search traversal is : \n";
    g.BFS (s);
    return 0;
}
