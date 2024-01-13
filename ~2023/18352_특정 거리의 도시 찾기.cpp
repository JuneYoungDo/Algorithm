//
// Created by June Young Do on 2022/07/13.
//

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int N, M, K, X;
vector<int> ans;
queue<int> q;
vector<int> v[300002];
bool visited[300002];
int length[300002];

void bfs(int start) {
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (length[now] == K) {
            ans.push_back(now);
            continue;
        }
        for (int i = 0; i < v[now].size(); i++) {
            if (visited[v[now][i]]) { continue; }
            q.push(v[now][i]);
            visited[v[now][i]] = true;
            length[v[now][i]] = length[now] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    bfs(X);
    if (ans.size() == 0) {
        cout << -1 << endl;
    } else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}