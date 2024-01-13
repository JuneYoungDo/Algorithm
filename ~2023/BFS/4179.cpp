//
// Created by June Young Do on 2021/09/06.
//

#include<iostream>
#include<queue>
#include<string>

using namespace std;
#define endl '\n'

int ans;
int manSize;
int fireSize;
int R, C, cnt;
string map[1001];
bool visit[1001][1001];             // visit없이 해서 메모리 초과 많이 남
queue<pair<int, int>> fireQ;
queue<pair<int, int>> manQ;
pair<int, int> moveM[4] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

// 불이 퍼질 수 있는 칸인가
bool isValidFire(int pointY, int pointX) {
    if (pointY < 0 || pointY >= R || pointX < 0 || pointX >= C)
        return false;
    if (map[pointY][pointX] == '#' || map[pointY][pointX] == 'F')
        return false;
    return true;
}

// 사람이 움직일 수 있는 칸인가
bool isValidMan(int pointY, int pointX) {
    if (visit[pointY][pointX])
        return false;
    if (pointY < 0 || pointY >= R || pointX < 0 || pointX >= C)
        return false;
    if (map[pointY][pointX] == 'F' || map[pointY][pointX] == '#')
        return false;
    return true;
}

int bfs() {
    while (!manQ.empty()) {
        fireSize = fireQ.size();        // for문에 바로 fireQ.size() 넣었다가 이중포문 속에서 fireQ가 들어나는 것 생각못해서 고생함
        while (fireSize--) {
            pair<int, int> now = fireQ.front();
            fireQ.pop();
            for (int j = 0; j < 4; j++) {
                int nextY = now.first + moveM[j].first;
                int nextX = now.second + moveM[j].second;
                if (isValidFire(nextY, nextX)) {
                    fireQ.push(make_pair(nextY, nextX));
                    map[nextY][nextX] = 'F';
                }
            }
        }

        manSize = manQ.size();
        while (manSize--) {
            pair<int, int> now = manQ.front();
            manQ.pop();

            if (now.first == 0 || now.first == R - 1 || now.second == 0 || now.second == C - 1) {   // R과 C 뒤집어 놓고 많이 틀림
                return cnt + 1;
            }
            for (int j = 0; j < 4; j++) {
                int nextY = now.first + moveM[j].first;
                int nextX = now.second + moveM[j].second;

                if (isValidMan(nextY, nextX)) {
                    manQ.push(make_pair(nextY, nextX));
                    visit[nextY][nextX] = true;
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> map[i];
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'J') {
                manQ.push(make_pair(i, j));
                visit[i][j] = true;
            }
            if (map[i][j] == 'F')
                fireQ.push(make_pair(i, j));
        }
    }

    ans = bfs();

    if (ans == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans << endl;

    return 0;
}