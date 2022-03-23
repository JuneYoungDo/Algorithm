//
// Created by June Young Do on 2022/03/23.
//
#include<iostream>
#include<algorithm>

using namespace std;
#define endl '\n'

int N, M, H;
int answer = 987654321;
bool visit[11][31];

bool isSuccess() {
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        for (int j = 1; j <= H; j++) {
            if (visit[tmp][j] == true) tmp = tmp + 1;
            else if (visit[tmp - 1][j] == true) tmp = tmp - 1;
        }
        if (tmp != i)return false;
    }
    return true;
}

void dfs(int tmp, int cnt) {
    if (cnt > 3)return;
    if (isSuccess()) {
        answer = min(answer, cnt);
        return;
    }

    for (int i = tmp; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (visit[j][i])continue;
            if (visit[j - 1][i])continue;
            if (visit[j + 1][i])continue;
            visit[j][i] = true;
            dfs(i, cnt + 1);
            visit[j][i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        visit[y][x] = true;
    }
    dfs(1, 0);

    if (answer == 987654321)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}
