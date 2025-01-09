#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/* 
 * Function to add an edge to the graph
 * The graph is represented by an adjacency list where each node points to its neighbors 
 * along with the edge weights.
 */
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});  // Undirected graph, so we add the reverse edge too
}

/* 
 * Dijkstra's algorithm implementation using a priority queue (min-heap).
 * This function computes the shortest distance from the source node to all other nodes in the graph.
 * The algorithm updates the distance array to store the shortest path for each node.
 */
void dijkstra(int source, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    
    dist[source] = 0;  // The distance to the source node is 0
    pq.push({0, source});  // Push source node with distance 0 into the priority queue

    while (!pq.empty()) {
        int node = pq.top().second;  // Get the node with the smallest distance
        int nodeDist = pq.top().first;
        pq.pop();  // Remove the node from the priority queue

        // If the current node's distance is greater than the already found distance, skip it
        if (nodeDist > dist[node]) continue;

        // Loop through all adjacent nodes of the current node
        for (auto &neighbor : adj[node]) {
            int adjNode = neighbor.first;  // Neighbor node
            int weight = neighbor.second;  // Weight of the edge to the neighbor

            // Relaxation step: If a shorter path to the neighbor is found, update its distance
            if (nodeDist + weight < dist[adjNode]) {
                dist[adjNode] = nodeDist + weight;  // Update the shortest distance
                pq.push({dist[adjNode], adjNode});  // Push the updated distance to the priority queue
            }
        }
    }
}

/* 
 * Main function to set up the graph, run Dijkstra's algorithm, and print the results.
 * In this example, we have a graph with 5 vertices (0 to 4) and a few edges with weights.
 */
int main() {
    int V = 5;  // Number of vertices
    vector<vector<pair<int, int>>> adj(V);  // Adjacency list (pair: {node, weight})

    // Adding edges to the graph (u, v, weight)
     addEdge(adj, 0, 1, 7);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 3, 4, 7);

    vector<int> dist(V, 1e9);  // Distance array initialized to "infinity/1e9"

    // Run Dijkstra's algorithm from source node 0
    dijkstra(0, adj, dist);

    // Print the shortest distances from source node 0 to all other nodes
    cout << "Shortest distances from source node 0:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
