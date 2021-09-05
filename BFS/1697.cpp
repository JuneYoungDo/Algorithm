//
// Created by June Young Do on 2021/09/03.
//

#include<iostream>
#include<queue>

using namespace std;
#define endl '\n'

int n, m;
bool visited[100001];

bool isValid(int x) {       // 조건에 맞는지 확인
    if (x >= 0 && x <= 100000 && !visited[x])
        return true;
    return false;
}

int bfs(int start, int end) {
    // pair<현재 점의 위치, 움직인 횟수>
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        int nowP = q.front().first;
        int nowC = q.front().second;
        q.pop();
        if (nowP == end) {
            return nowC;
        }
        if (isValid(nowP + 1)) {                    // 한칸 갔을 경우
            q.push({nowP + 1, nowC + 1});
            visited[nowP + 1] = true;
        }
        if (isValid(nowP - 1)) {                    // 한칸 뒤로 갔을 경우
            q.push({nowP - 1, nowC + 1});
            visited[nowP - 1] = true;
        }
        if (isValid(2 * nowP)) {                    // *2로 순간이동 한 경우
            q.push({nowP * 2, nowC + 1});
            visited[nowP * 2] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cout << bfs(n, m) << endl;

    return 0;
}