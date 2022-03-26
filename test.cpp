#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int R, C, ans;
char graph[21][21];
bool isUsed[30];
pair<int, int> moveRange[4] = {{1,  0},
                               {0,  1},
                               {-1, 0},
                               {0,  -1}};

bool validation(int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C) return false;
    return true;
}

void dfs(int y, int x, int cnt) {
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++) {
        int nextY = y + moveRange[i].first;
        int nextX = x + moveRange[i].second;
        if (validation(nextY, nextX)) {
            if (isUsed[graph[nextY][nextX] - 'A'] == false) {
                isUsed[graph[nextY][nextX] - 'A'] = true;
                dfs(nextY, nextX, cnt + 1);
                isUsed[graph[nextY][nextX] - 'A'] = false;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> graph[i][j];

    isUsed[graph[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ans << endl;

    return 0;
}