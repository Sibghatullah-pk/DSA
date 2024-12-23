#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

// Function to perform BFS
void BFS(int startNode, map<int, list<int>> &adjList, map<int, bool> &visited)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse all the neighbors of the current node
        for (const int &neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    // Number of edges and nodes
    int e, n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    map<int, list<int>> adjList; // Adjacency list using map of lists
    map<int, bool> visited;      // Visited map

    cout << "Enter the edges (node1 node2):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
        visited[u] = false;      // Initialize visited map
        visited[v] = false;
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    // Perform BFS
    BFS(startNode, adjList, visited);

    return 0;
}
