//
// Created by June Young Do on 2022/07/25.
//
#include<iostream>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define endl '\n'

int n, m;
int num = 1;
char mp[1001][1001];
int visit[1001][1001];

int my[4] = {0, 0, 1, -1};
int mx[4] = {1, -1, 0, 0};

map<int, int> numCnt;
int matching[1001][1001];
set<int> matchingVisit;

void bfs(int i, int j) {
    int ret = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = 1;
    matching[i][j] = num;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) { continue; }
            if (mp[ny][nx] == '1') { continue; }
            if (visit[ny][nx]) { continue; }
            ret++;
            q.push({ny, nx});
            visit[ny][nx] = true;
            matching[ny][nx] = num;
        }
    }
    numCnt[num] = ret;
}

int bfsV2(int i, int j) {
    matchingVisit.clear();
    int ret = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + my[i];
            int nx = x + mx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) { continue; }
            if (mp[ny][nx] == '1') { continue; }
            if (matching[ny][nx] != 0) {
                if (matchingVisit.find(matching[ny][nx]) == matchingVisit.end()) {
                    ret += numCnt[matching[ny][nx]];
                    matchingVisit.insert(matching[ny][nx]);
                    continue;
                }
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            mp[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '0') {
                if (visit[i][j]) { continue; }
                bfs(i, j);
                num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '0') { cout << 0; }
            else {
                cout << bfsV2(i, j) % 10;
            }
        }
        cout << endl;
    }

    return 0;
}
