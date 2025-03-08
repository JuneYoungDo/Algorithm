//
// Created by June Young Do on 3/8/25.
//

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
#define endl '\n'

vector<int> graph[1001];
bool check[1001];

void dfs(int start) {
    check[start] = true;
    cout << start << ' ';
    for (int i = 0; i < graph[start].size(); i++) {
        if (!check[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';

        for (int i = 0; i < graph[now].size(); i++) {
            if (!check[graph[now][i]]) {
                q.push(graph[now][i]);
                check[graph[now][i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(check, false, sizeof(check));

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;
    memset(check, false, sizeof(check));
    bfs(v);
    cout << endl;
}