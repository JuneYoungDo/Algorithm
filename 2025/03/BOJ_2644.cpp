//
// Created by June Young Do on 3/20/25.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define endl '\n'

vector<int> v[101];
int visited[101];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < v[now].size(); i++) {
            if (visited[v[now][i]] != 0) {
                continue;
            } else {
                q.push(v[now][i]);
                visited[v[now][i]] = visited[now] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    int targetA, targetB;
    cin >> n;
    cin >> targetA >> targetB;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    bfs(targetA);

    cout << visited[targetB] - 1 << endl;

    return 0;
}