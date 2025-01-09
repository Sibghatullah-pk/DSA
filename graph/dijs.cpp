/*
->  aiik ajacent list (showing the distance as well)
->  aik set cahiya ota (jis ma (dis,node)) having node +distance)
->  aik distnce array bnany jis sa shortest path nikala ga(firstly os ko infinity pr rkta hn)


->  set ma data ky entry kra ga suppose source node is zero then 
        entry krna k bad source tu first of all zero distance pr hy ho 
        ga tu osa top node kr ka distance wla jo array bnaya tha os ma 
        data enter kr da ga 
-> * Key Steps:
 * 1. Use an adjacency list to represent the graph.
 * 2. Maintain a distance array initialized to a large value (e.g., 1e9 for infinity).
 * 3. Use a set to efficiently pick the node with the smallest distance.
 * 4. Perform relaxation on all adjacent nodes to update distances.
 * 5. Print the shortest distances from the source node.
 * 
 * Time Complexity: O((V + E) * log(V)) where V = vertices, E = edges.
 * 

*/


#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to create an adjacency list
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // For undirected graph
}

// Dijkstra's algorithm implementation
void dijkstra(int source, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    set<pair<int, int>> s;

    // Initialize the distance of the source to 0
    dist[source] = 0;
    s.insert({0, source});

    while (!s.empty()) {
        auto top = *(s.begin());
        s.erase(s.begin());

        int nodeDistance = top.first;
        int node = top.second;

        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor.first;
            int edgeWeight = neighbor.second;

            if (nodeDistance + edgeWeight < dist[adjNode]) {
                auto it = s.find({dist[adjNode], adjNode});
                if (it != s.end()) {
                    s.erase(it);
                }
                dist[adjNode] = nodeDistance + edgeWeight;
                s.insert({dist[adjNode], adjNode});
            }
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    const int INF = 1e9; // Use a large constant to represent infinity
    vector<vector<pair<int, int>>> adj(V); // Adjacency list

    // Add edges (u, v, weight)
    addEdge(adj, 0, 1, 7);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 3, 4, 7);

    // Distance array initialized to INF
    vector<int> dist(V, INF);

    // Run Dijkstra's algorithm from source node 0
    dijkstra(0, adj, dist);

    // Print the shortest distances from source
    cout << "Shortest distances from source node 0:" << endl;
    for (int i = 0; i < V; i++) {
        cout << dist[i]<<" " ;
    }

    return 0;
}
