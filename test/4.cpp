//
// Created by June Young Do on 2021/12/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
//4번

vector<bool> visit[502];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

string ReachTheEnd(vector<string> grid, int maxTime) {
    int n = grid.size();
    int m = grid[n - 1].size();
    for (int i = 0; i < n; i++)
        visit[i] = vector<bool>(m, 0);

    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = true;

    int d = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (grid[ni][nj] == '#') continue;
                if (visit[ni][nj]) continue;
                visit[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        d++;
        if (visit[n - 1][m - 1]) break;
    }
    bool avail = false;
    if (visit[n - 1][m - 1] && d <= maxTime) avail = true;
    return avail ? "Yes" : "No";
}