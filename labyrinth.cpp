#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    char dir[] = {'D', 'R', 'U', 'L'};

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (make_pair(x, y) == end) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int ni = x + dx[d];
            int nj = y + dy[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !visited[ni][nj] && (grid[ni][nj] == '.' || grid[ni][nj] == 'B')) {
                visited[ni][nj] = true;
                parent[ni][nj] = {x, y};
                q.push({ni, nj});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string path;
        pair<int, int> cur = end;
        while (cur != start) {
            auto [px, py] = parent[cur.first][cur.second];
            for (int d = 0; d < 4; ++d) {
                if (px + dx[d] == cur.first && py + dy[d] == cur.second) {
                    path += dir[d];
                    break;
                }
            }
            cur = {px, py};
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n" << path << "\n";
    }
}
