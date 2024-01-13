//
// Created by June Young Do on 2022/07/14.
//

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;
#define endl '\n';

int n, m;
int start, finish;
int maxWeight;
vector<pair<int, int>> graph[100001];
bool visited[100001];

bool bfs(int c) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        if (tmp == finish)
            return true;

        for (int i = 0; i < graph[tmp].size(); i++) {
            int next = graph[tmp][i].first;
            int nextWeight = graph[tmp][i].second;

            if (!visited[next] && c <= nextWeight) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));

        maxWeight = max(maxWeight, c);
    }
    cin >> start >> finish;

    int left = 0, right = maxWeight;
    while (left <= right) {
        memset(visited, false, sizeof(visited));

        int mid = (left + right) / 2;
        if (bfs(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << right << endl;

    return 0;
}