#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; // Adjacency list
int color[100005]; // Color array (0 or 1, -1 means unvisited)

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring with color 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Check all neighbors
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) { // If the neighbor is unvisited
                // Color the neighbor with the opposite color
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) { 
                // Conflict: both have the same color
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Read the graph (friendships)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize color array with -1 (unvisited)
    memset(color, -1, sizeof(color));

    // Try to color the graph and check for bipartiteness
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) { // If the node is not visited
            if (!bfs(i)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    // If the graph is bipartite, print the team assignments (1 and 2 for the two sets)
    // cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << color[i] + 1 << " "; // Convert 0/1 to 1/2 for team numbers
    }
    cout << "\n";

    return 0;
}
