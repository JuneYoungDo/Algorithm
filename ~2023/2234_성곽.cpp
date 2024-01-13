//
// Created by June Young Do on 2022/07/13.
//

#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;
#define endl '\n'

int N, M;
int roomCnt;        // 방 갯수
int maxRoom;

int mp[51][51];
int roomNum[51][51];    // 방 번호
int roomSize[25002];    // 방 크기
int visited[51][51];

int mx[4] = {-1, 0, 1, 0};          // 북, 서, 남, 동
int my[4] = {0, -1, 0, 1};

int bfs(int y, int x, int num) {
    int tmp = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;
    roomNum[y][x] = num;
    tmp++;
    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + my[i];
            int nextX = nowX + mx[i];

            int tp = pow(2, i);
            if (mp[nowY][nowX] & tp) { continue; }
            if (visited[nextY][nextX]) { continue; }
            q.push({nextY, nextX});
            visited[nextY][nextX] = true;
            roomNum[nextY][nextX] = num;
            tmp++;
        }
    }
    maxRoom = max(maxRoom, tmp);
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                roomCnt++;
                roomSize[roomCnt] = bfs(i, j, roomCnt);
            }
        }
    }

    cout << roomCnt << endl;
    cout << maxRoom << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int nxtY = i + my[k];
                int nxtX = j + mx[k];
                int tp = pow(2, k);
                if (mp[i][j] & tp && roomNum[i][j] != roomNum[nxtY][nxtX]) {
                    int sumSize = roomSize[roomNum[i][j]] + roomSize[roomNum[nxtY][nxtX]];
                    maxRoom = max(sumSize, maxRoom);
                }
            }
        }
    }

    cout << maxRoom << endl;

    return 0;
}
