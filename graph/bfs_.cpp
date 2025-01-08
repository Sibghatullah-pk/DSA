#include <unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <iostream> // For input/output

using namespace std;

// Function to prepare the adjacency list
void prepareAdjList(unordered_map<int, set<int>> &adjList, const vector<pair<int, int>> &edges) {
    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;

        // Add edge to the adjacency list
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

// BFS function to traverse the graph starting from a given node
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // Traverse all neighbors of the current node
        for (const auto &neighbor : adjList[frontNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// Function to perform BFS on the entire graph
vector<int> BFS(int vertex, const vector<pair<int, int>> &edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Prepare the adjacency list
    prepareAdjList(adjList, edges);

    // Traverse all components to ensure disconnected graphs are covered
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// Main function to test the BFS implementation
int main() {
    // Example graph: 5 vertices (0, 1, 2, 3, 4) and edges
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}
    };
    int vertex = 5;

    vector<int> result = BFS(vertex, edges);

    // Print the BFS traversal result
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
