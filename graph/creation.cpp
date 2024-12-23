#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    // Add an edge to the graph
    void addEdge(int u, int v, bool direction) {
        // 0 means undirected
        // 1 means directed
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    // Print the adjacency list
    void printAdjList() {
        unordered_map<int, list<int>>::iterator it;
        for (it = adj.begin(); it != adj.end(); ++it) {
            cout << it->first << " -> ";
            for (auto i = it->second.begin(); i != it->second.end(); ++i) {
                cout << *i << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // Assuming undirected graph
    }

    // Print adjacency list
    g.printAdjList();

    return 0;
}
