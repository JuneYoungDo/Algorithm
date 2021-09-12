#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


struct point {
    int y, x, val;
};

const int INF = 7654321;
int tc, n, m, map[104][104];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int p[3][104][104];

struct cmp{
    bool operator()(point a, point b) {
        return a.val > b.val;
    }
};

int res = INF;

vector<point> man;

void bfs(int y, int x, int num) {
    priority_queue<point, vector<point>, cmp> q;
    bool visit[104][104] = { false, };

    q.push({y, x, 0});
    visit[y][x] = true;
    p[num][y][x] = 0;

    while (!q.empty()) {
        point t = q.top();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = t.y + dy[i];
            int tx = t.x + dx[i];
            int tval = t.val;

            if (ty < 0 || ty >= n + 2 || tx < 0 || tx >= m + 2) continue;
            if (visit[ty][tx] || map[ty][tx] == 1) continue;

            if (map[ty][tx] == 2) tval++;

            q.push({ty, tx, tval});
            visit[ty][tx] = true;
            p[num][ty][tx] = tval;
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        man.clear();

        man.push_back({ 0, 0 });

        cin >> n >> m;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                    map[i][j] = 0;
                    continue;
                }

                char c;
                cin >> c;

                if (c == '.') {
                    map[i][j] = 0;
                }
                else if (c == '#') {
                    map[i][j] = 2;
                }
                else if (c == '*') {
                    map[i][j] = 1;
                }
                else {
                    map[i][j] = 3;
                    man.push_back({ i, j });
                }
            }
        }

        for (int z = 0; z < 3; z++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    //p[z][i][j] = INF;
                }
            }
        }

        for (int num = 0; num < 3; num++) {
            bfs(man[num].y, man[num].x, num);
        }


        long long ans = INF;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (map[i][j] == 1) continue;

                long long tmp = 0;
                for (int z = 0; z < 3; z++) {
                    tmp += p[z][i][j];
                }

                if (map[i][j] == 2) tmp -= 2;

                ans = min(ans, tmp);

            }
        }

        cout << ans << '\n';
    }

    return 0;
}